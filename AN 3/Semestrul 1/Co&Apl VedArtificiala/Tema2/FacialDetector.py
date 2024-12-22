from Parameters import *
from skimage.feature import hog
import numpy as np
from tqdm import tqdm
import pickle
from sklearn.svm import LinearSVC
from copy import deepcopy
import matplotlib.pyplot as plt

class FacialDetector:
    def __init__(self, params: Parameters):
        self.params = params
        self.best_model = None

    def get_positive_descriptors(self):
        images_path = self.params.positive_train_folder_path
        files = os.listdir(images_path)
        positive_descriptors = []
        for i in tqdm(range(len(files)), miniters=len(files) // 100):
            img = cv.imread(os.path.join(images_path, files[i]), cv.IMREAD_GRAYSCALE)
            features = hog(img, pixels_per_cell = (self.params.dim_hog_cell, self.params.dim_hog_cell), cells_per_block=(2, 2), feature_vector=True)
            
            positive_descriptors.append(features)
            if self.params.use_flip_images:
                features = hog(np.fliplr(img), pixels_per_cell=(self.params.dim_hog_cell, self.params.dim_hog_cell), cells_per_block=(2, 2), feature_vector=True)
                positive_descriptors.append(features)

            #can also use other augmentations here. No need to create pictures

        positive_descriptors = np.array(positive_descriptors)
        return positive_descriptors
    
    def get_negative_descriptors(self):
        images_path = self.params.negative_train_folder_path
        original_files = os.listdir(images_path)
        files = []
        n = self.params.n_negative_examples
        while n:
            file_index = np.random.randint(0, len(original_files))
            files.append(original_files[file_index])
            del original_files[file_index]
            n -= 1
        negative_descriptors = []
        print(len(files))

        for i in tqdm(range(len(files)), miniters=len(files) // 100):
            img = cv.imread(os.path.join(images_path, files[i]), cv.IMREAD_GRAYSCALE)
            descr = hog(img, pixels_per_cell=(self.params.dim_hog_cell, self.params.dim_hog_cell), cells_per_block=(2, 2), feature_vector = False)
            negative_descriptors.append(descr.flatten())

        negative_descriptors = np.array(negative_descriptors)
        return negative_descriptors

    def train_classifier(self, X, y):
        svm_file_name = os.path.join(self.params.this_model_save_files_path, 
                                    f'best_model_{self.params.dim_hog_cell}_{self.params.n_negative_examples}')
        if os.path.exists(svm_file_name):
            self.best_model = pickle.load(open(svm_file_name, 'rb'))
            return

        best_accuracy = 0
        best_c = 0
        best_model = None
        Cs = [10 ** -5, 10 ** -4,  10 ** -3,  10 ** -2, 10 ** -1, 10 ** 0]
        for c in Cs:
            model = LinearSVC(C=c)
            model.fit(X, y)
            acc = model.score(X, y)
            print(acc)
            if acc > best_accuracy:
                best_accuracy = acc
                best_c = c
                best_model = deepcopy(model)
                
        print('Performanta clasificatorului optim pt c = %f' % best_c)
        pickle.dump(best_model, open(svm_file_name, 'wb'))

        scores = best_model.decision_function(X)
        self.best_model = best_model
        positive_scores = scores[y > 0]
        negative_scores = scores[y <= 0]

        plt.plot(np.sort(positive_scores))
        plt.plot(np.zeros(len(positive_scores)))
        plt.plot(np.sort(negative_scores))
        plt.xlabel('Nr example antrenare')
        plt.ylabel('Scor clasificator')
        plt.title('Distributia scorurilor clasificatorului pe exemplele de antrenare')
        plt.legend(['Scoruri exemple pozitive', '0', 'Scoruri exemple negative'])
        plt.show()  

    def intersection_over_union(self, bbox_a, bbox_b):
        x_a = max(bbox_a[0], bbox_b[0])
        y_a = max(bbox_a[1], bbox_b[1])
        x_b = min(bbox_a[2], bbox_b[2])
        y_b = min(bbox_a[3], bbox_b[3])

        inter_area = max(0, x_b - x_a + 1) * max(0, y_b - y_a + 1)

        box_a_area = (bbox_a[2] - bbox_a[0] + 1) * (bbox_a[3] - bbox_a[1] + 1)
        box_b_area = (bbox_b[2] - bbox_b[0] + 1) * (bbox_b[3] - bbox_b[1] + 1)

        iou = inter_area / float(box_a_area + box_b_area - inter_area)

        return iou

    def non_maximal_suppression(self, image_detections, image_scores, image_size):
        # xmin, ymin, xmax, ymax
        x_out_of_bounds = np.where(image_detections[:, 2] > image_size[1])[0]
        y_out_of_bounds = np.where(image_detections[:, 3] > image_size[0])[0]
        print(x_out_of_bounds, y_out_of_bounds)
        image_detections[x_out_of_bounds, 2] = image_size[1]
        image_detections[y_out_of_bounds, 3] = image_size[0]
        sorted_indices = np.flipud(np.argsort(image_scores))
        sorted_image_detections = image_detections[sorted_indices]
        sorted_scores = image_scores[sorted_indices]

        is_maximal = np.ones(len(image_detections)).astype(bool)
        iou_threshold = 0.3
        for i in range(len(sorted_image_detections) - 1):
            if is_maximal[i] == True:  # don't change to 'is True' because is a numpy True and is not a python True :)
                for j in range(i + 1, len(sorted_image_detections)):
                    if is_maximal[j] == True:  # don't change to 'is True' because is a numpy True and is not a python True :)
                        if self.intersection_over_union(sorted_image_detections[i],sorted_image_detections[j]) > iou_threshold:is_maximal[j] = False
                        else:  # verificam daca centrul detectiei este in mijlocul detectiei cu scor mai mare
                            c_x = (sorted_image_detections[j][0] + sorted_image_detections[j][2]) / 2
                            c_y = (sorted_image_detections[j][1] + sorted_image_detections[j][3]) / 2
                            if sorted_image_detections[i][0] <= c_x <= sorted_image_detections[i][2] and \
                                    sorted_image_detections[i][1] <= c_y <= sorted_image_detections[i][3]:
                                is_maximal[j] = False
        return sorted_image_detections[is_maximal], sorted_scores[is_maximal]

    def run(self):
        test_files = os.listdir(self.params.test_folder_path)
        detections = None
        scores = np.array([])
        file_names = np.array([])
        
        w = self.best_model.coef_.T
        bias = self.best_model.intercept_[0]
        descriptors_to_return = []
        for i in range(len(test_files)):
            img = cv.imread(os.path.join(self.params.test_folder_path, test_files[i]), cv.IMREAD_GRAYSCALE)
            image_scores = []
            image_detections = []
            hog_descriptors = hog(img, pixels_per_cell=(self.params.dim_hog_cell, self.params.dim_hog_cell), cells_per_block=(2, 2), feature_vector=False)
            
            num_cols = img.shape[1] // self.params.dim_hog_cell - 1
            num_rows = img.shape[0] // self.params.dim_hog_cell - 1
            num_cell_in_template = self.params.dim_window // self.params.dim_hog_cell - 1

            for y in range(0, num_rows - num_cell_in_template):
                for x in range(0, num_cols - num_cell_in_template):
                    descr = hog_descriptors[y: y + num_cell_in_template, x: x + num_cell_in_template].flatten()
                    score = np.dot(descr, w)[0] + bias
                    if score > self.params.threshold:
                        x_min = int(x * self.params.dim_hog_cell)
                        y_min = int(y * self.params.dim_hog_cell)
                        x_max = int(x * self.params.dim_hog_cell + self.params.dim_window)
                        y_max = int(y * self.params.dim_hog_cell + self.params.dim_window)
                        image_detections.append([x_min, y_min, x_max, y_max])
                        image_scores.append(score)
                if len(image_scores) > 0:
                    image_detections, image_scores = self.non_maximal_suppression(np.array(image_detections), np.array(image_scores), img.shape)
                    
                if len(image_scores) > 0:
                    if detections is None:
                        detections = image_detections
                    else:
                        detections = np.concatenate((detections, image_detections))
                    scores = np.append(scores, image_scores)
                    short_name = test_files[i]
                    image_names = [short_name for _ in range(len(image_scores))]
                    file_names = np.append(file_names, image_names)

        return detections, scores, file_names
