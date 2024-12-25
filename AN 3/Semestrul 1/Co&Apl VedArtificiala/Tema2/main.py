from Parameters import *
from FacialDetector import *

def generate_annotations(params: Parameters):
    facialDetector = FacialDetector(params)
    positive_features_path = params.positive_descriptors_path
    if os.path.exists(positive_features_path):
        positive_features = np.load(positive_features_path)
    else:
        positive_features = facialDetector.get_positive_descriptors()
        np.save(positive_features_path, positive_features)

    negative_features_path = params.negative_descriptors_path
    if os.path.exists(negative_features_path):
        negative_features = np.load(negative_features_path)
    else:
        negative_features = facialDetector.get_negative_descriptors()
        np.save(negative_features_path, negative_features)

    X = np.concatenate((np.squeeze(positive_features), np.squeeze(negative_features)), axis=0)
    y = np.concatenate((np.ones(positive_features.shape[0]), np.zeros(negative_features.shape[0])))
    facialDetector.train_classifier(X, y)
    detections, scores, file_names = facialDetector.run()
    return detections, scores, file_names

def write_to_file(detections, scores, file_names, params:Parameters):
    g = open(f"Output_{params.OX_dim_window}x{params.OY_dim_window}", "x")
    for (detection, score, file_name) in zip(detections, scores, file_names):
        g.write(f'{file_name} {detection[0]} {detection[1]} {detection[2]} {detection[3]} {score}\n')
    g.close()


params1 = Parameters(OX_dim_window=64, OY_dim_window=128, extract_examples=False, dim_hog_cell=6, dim_descriptor_cell=36, overlap=0.5, threshold=5, use_flip_images=True, other_augmentations=True, use_salt_and_pepper = True, n_negative_examples=150000)
params2 = Parameters(OX_dim_window=128, OY_dim_window=128, extract_examples=False, dim_hog_cell=6, dim_descriptor_cell=36, overlap=0.5, threshold=5, use_flip_images=True, use_salt_and_pepper = True, other_augmentations = True, n_negative_examples=150000)
params3 = Parameters(OX_dim_window=128, OY_dim_window=64, extract_examples=False, dim_hog_cell=6, dim_descriptor_cell=36, overlap=0.5, threshold=5, use_flip_images=True, use_salt_and_pepper = True, other_augmentations=True, n_negative_examples=150000)

a = [params1, params2, params3]
for params in a:
    detections, scores, file_names = generate_annotations(params)
    write_to_file(detections, scores, file_names, params)

lookup = dict()#{'image_name': ([rectangles], [scores])}
for params in a:
    g = open(f'Output_{params.OX_dim_window}x{params.OY_dim_window}', 'r')
    for line in g.readlines():
        line = line.strip().split()
        if line[0] not in lookup:
            lookup.update({line[0]: ([], [])})
        lookup[line[0]][0].append([int(line[1]), int(line[2]), int(line[3]), int(line[4])])
        lookup[line[0]][1].append(float(line[5]))


x = FacialDetector(Parameters(OX_dim_window=64, OY_dim_window=128, extract_examples=False, dim_hog_cell=6, dim_descriptor_cell=36, overlap=0.7, threshold=7, use_flip_images=True, use_salt_and_pepper=True, n_negative_examples=-1))

detections_to_save = []
file_names_to_save = []
scores_to_save = []
for image in lookup.keys():
    img = cv.imread(os.path.join(params1.test_folder_path, image), cv.IMREAD_GRAYSCALE)
    #show_image('img', img)
    detections, scores = x.non_maximal_suppression(np.array(lookup[image][0]), np.array(lookup[image][1]), img.shape)
    for detection, score in zip(detections, scores):
        detections_to_save.append(np.array([detection[0], detection[1], detection[2], detection[3]]))
        scores_to_save.append(score)
        file_names_to_save.append(image)
        # cv.putText(img, str(score), (detection[0], detection[1] - 10), cv.FONT_HERSHEY_COMPLEX, 0.9, (0, 255, 255), 2)
        # cv.rectangle(img, (detection[0], detection[1]), (detection[2], detection[3]), (0, 255, 255), 3)
    #show_image('img', img)

output_folder = os.path.join(params1.base_dir, 'output')
os.makedirs(output_folder, exist_ok=True)
np.save(os.path.join(output_folder, 'detections_all_faces.npy'), detections_to_save)
np.save(os.path.join(output_folder, 'file_names_all_faces'), file_names_to_save)
np.save(os.path.join(output_folder, 'scores_all_faces.npy'), scores_to_save)

import evaluare.cod_evaluare.evalueaza_solutie


