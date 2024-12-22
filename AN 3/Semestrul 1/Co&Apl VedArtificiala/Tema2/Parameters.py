import os
import cv2 as cv

#folder: Positive36x36
    #1.jpg
    #2.jpg
    #3.jpg

def show_image(title, image):
    image = cv.resize(image, (0, 0), fx=0.5, fy=0.5)
    cv.imshow(title, image)
    cv.waitKey(0)
    cv.destroyAllWindows()

def intersectie_dreptunghi(d1, d2):
    d1_x_top_left, d1_y_top_left, d1_x_bottom_right, d1_y_bottom_right = d1
    d2_x_top_left, d2_y_top_left, d2_x_bottom_right, d2_y_bottom_right = d2

    return (d1_x_top_left <= d2_x_bottom_right 
            and d1_x_bottom_right >= d2_x_top_left
            and d1_y_top_left <= d2_y_bottom_right
            and d1_y_bottom_right >= d2_y_top_left)

class Annotation():
    def __init__(self, image_name, x_top_left, y_top_left, x_bottom_right, y_bottom_right, person):
        self.image_name = image_name
        self.x_top_left = int(x_top_left)
        self.y_top_left = int(y_top_left)
        self.x_bottom_right = int(x_bottom_right)
        self.y_bottom_right = int(y_bottom_right)
        self.person = person

    def __str__(self):
        return f'Person {self.person} is in image {self.image_name}, starting at ({self.x_top_left}, {self.y_top_left}) and ending at ({self.x_bottom_right}, {self.y_bottom_right})'

class Parameters:
    def __init__(self, OX_dim_window: int, OY_dim_window: int, extract_examples: bool, dim_hog_cell: int, dim_descriptor_cell: int, overlap, threshold, use_flip_images: bool, n_negative_examples, verbose:bool = False): # L = lungime, W = inaltime
        self.OX_dim_window = OX_dim_window
        self.OY_dim_window = OY_dim_window
        
        self.dim_hog_cell = dim_hog_cell
        self.dim_descriptor_cell = dim_descriptor_cell
        self.overlap = overlap
        self.threshold = threshold
        self.use_flip_images = use_flip_images
        self.n_negative_examples = n_negative_examples # so that we don't use all 500.000 examples. Some are similar

        self.base_dir = os.getcwd()
        self.my_folder = 'proprii'
        self.positive_train_folder = f'Positive{OX_dim_window}x{OY_dim_window}' #folder cu exemple positive de dimensiune L_window x W_window
        self.negative_train_folder = f'Negative{OX_dim_window}x{OY_dim_window}' #folder cu exemple negative de dimensiune L_window x W_window
        self.positive_train_folder_path = os.path.join(os.path.join(self.base_dir, self.my_folder), self.positive_train_folder)
        self.negative_train_folder_path = os.path.join(os.path.join(self.base_dir, self.my_folder), self.negative_train_folder)
       
        self.models_folder = 'model_saves'
        self.models_folder_path = os.path.join(self.my_folder, self.models_folder)
        self.this_model_save_files = f"model_{OX_dim_window}x{OY_dim_window}"
        self.this_model_save_files_path = os.path.join(self.models_folder_path, self.this_model_save_files)
        
        self.test_folder = 'antrenare'
        self.test_folder_path = os.path.join(self.base_dir, self.test_folder)

        self.descriptors_folder = 'descriptors'
        self.descriptors_folder_path = os.path.join(self.my_folder, self.descriptors_folder)
        self.positive_descriptors_path = os.path.join(self.descriptors_folder_path, f'descriptoriPozitivi_{self.dim_hog_cell}_{self.dim_descriptor_cell}_{self.OX_dim_window}x{self.OY_dim_window}.npy')
        self.negative_descriptors_path = os.path.join(self.descriptors_folder_path, f'descriptoriNegativi_{self.dim_hog_cell}_{self.dim_descriptor_cell}_{self.OX_dim_window}x{self.OY_dim_window}.npy')
        
        os.makedirs(self.my_folder, exist_ok=True)
        os.makedirs(os.path.join(self.my_folder, self.positive_train_folder), exist_ok=True)
        os.makedirs(os.path.join(self.my_folder, self.negative_train_folder), exist_ok=True)
        os.makedirs(self.models_folder_path, exist_ok=True)
        os.makedirs(self.this_model_save_files_path, exist_ok=True)
        os.makedirs(self.descriptors_folder_path, exist_ok=True)

        if self.n_negative_examples == -1:
            self.n_negative_examples = os.listdir(self.negative_train_folder_path)

        if extract_examples:
            train_folder = os.path.join(self.base_dir, 'antrenare')
            folders = [x for x in os.listdir(train_folder) if '.' not in x]
            for folder in folders:
                g = open(os.path.join(train_folder, folder)+'_annotations.txt', 'r')
                annotations = [x.strip().split() for x in g.readlines()]
                annotations = [Annotation(x[0], x[1], x[2], x[3], x[4], x[5]) for x in annotations]

                for annotation in annotations: #redraw the square so that it fits into L_window, W_window. Extract positive examples
                    image = cv.imread(os.path.join(os.path.join(train_folder, folder), annotation.image_name), cv.IMREAD_GRAYSCALE)
                    patch = image[annotation.y_top_left: annotation.y_bottom_right, annotation.x_top_left: annotation.x_bottom_right]
                    patch = cv.resize(patch, (OY_dim_window, OX_dim_window))
                    cv.imwrite(os.path.join(os.path.join(os.path.join(self.base_dir, 'proprii'), self.positive_train_folder), f'{annotation.person}_{folder}Dataset_{annotation.image_name}'), patch)
                    if verbose:
                        show_image('img', patch.copy())
                
                annotation_dict = dict([(x.image_name, []) for x in annotations])
                for x in annotations:
                    annotation_dict[x.image_name].append(x)
 
                step = 10
                cnt = 0
                for image_name in os.listdir(os.path.join(train_folder, folder)):
                    image = cv.imread(os.path.join(os.path.join(train_folder, folder), image_name), cv.IMREAD_GRAYSCALE)
                    annotations = annotation_dict[image_name]
                    if verbose:
                        for an in annotations:
                            cv.rectangle(image.copy(), (an.x_top_left, an.y_top_left), (an.x_bottom_right, an.y_bottom_right), (0, 255, 255), 3)
                    for x in range(0, image.shape[0] - OX_dim_window, step):
                        for y in range(0, image.shape[1] - OY_dim_window, step):

                            if verbose:
                                patch1 = image[x: x + OX_dim_window, y: y + OY_dim_window].copy()
                                show_image('patch extras', patch1)
                            ok = True
                            for annotation in annotations:
                                if intersectie_dreptunghi((y, x, y + OY_dim_window, x + OX_dim_window), 
                                                          (annotation.x_top_left, annotation.y_top_left, annotation.x_bottom_right, annotation.y_bottom_right)):
                                    ok = False
                                    break
                            if ok == False:
                                continue

                            try:
                                patch = image[x: x + OX_dim_window, y: y + OY_dim_window].copy()
                            except:
                                print(x, x + OX_dim_window, image.shape)
                            
                            if verbose:
                                cv.rectangle(image, (y, x), (y + OY_dim_window, x + OX_dim_window), (0, 255, 0), 3)
                                show_image('img', image)
                                show_image('img', patch)

                            cv.imwrite(os.path.join(os.path.join(os.path.join(self.base_dir, 'proprii'), self.negative_train_folder), f'{cnt}.jpg'), patch)
                            cnt += 1

