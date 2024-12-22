from Parameters import *
from FacialDetector import *

#a = Parameters(64, 128, True, False) #64 coloane, 128 linii
#a = Parameters(128, 128, True, False)
#b = Parameters(128, 64, True, False)

params1 = Parameters(OX_dim_window=64, OY_dim_window=128, extract_examples=False, dim_hog_cell=12, dim_descriptor_cell=36, overlap=0.3, threshold=0, use_flip_images=True, n_negative_examples=100000)

facialDetector1 = FacialDetector(params1)

positive_features_path1 = params1.positive_descriptors_path
if os.path.exists(positive_features_path1):
    positive_features1 = np.load(positive_features_path1)
else:
    positive_features1 = facialDetector1.get_positive_descriptors()
    np.save(positive_features_path1, positive_features1)

negative_features_path1 = params1.negative_descriptors_path
if os.path.exists(negative_features_path1):
    negative_features1 = np.load(negative_features_path1)
else:
    negative_features1 = facialDetector1.get_negative_descriptors()
    np.save(negative_features_path1, negative_features1)


X = np.concatenate((np.squeeze(positive_features1), np.squeeze(negative_features1)), axis=0)
y = np.concatenate((np.ones(positive_features1.shape[0]), np.zeros(negative_features1.shape[0])))
facialDetector1.train_classifier(X, y)

detections, scores, file_names = facialDetector1.run()

print(detections, scores, file_names)