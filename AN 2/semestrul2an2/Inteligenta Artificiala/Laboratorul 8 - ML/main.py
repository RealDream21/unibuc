import numpy as np
import matplotlib.pyplot as plt
from sklearn.naive_bayes import MultinomialNB

def values_to_bins(mat, intervale):
    matrice_discretizata = np.digitize(mat, intervale) - 1
    return matrice_discretizata

def confusion_matrix(y_true, y_pred):
    confusion_matrix = np.array([[0 for _ in range(10)] for _ in range(10)])
    for (predicted_label, true_label) in zip(y_pred, y_true):
        confusion_matrix[predicted_label][true_label] += 1
    return confusion_matrix



train_images = np.loadtxt('train_images.txt')
test_images = np.loadtxt('test_images.txt')
train_labes = np.loadtxt('train_labels.txt', 'int')
test_labels = np.loadtxt('test_labels.txt','int')

intervale = np.linspace(start=0, stop=255, num=5)
train_images_discretizata = values_to_bins(train_images, intervale)
test_images_discretizata = values_to_bins(test_images, intervale)

naive_bayes_model = MultinomialNB()
naive_bayes_model.fit(train_images_discretizata, train_labes)
naive_bayes_model.predict(test_images_discretizata)
print(naive_bayes_model.score(test_images_discretizata, test_labels))
#pentru 3 da 0.826
#pentru 5 da 0.836
#pentru 7 da 0.842
#pentru 9 da 0.842
#pentru 11 da 0.842

cnt_misclasate = 0
img_misclasate = []
labels_for_print = []
for (imagine, label) in zip(test_images_discretizata, test_labels):
    aux = []
    aux.append(imagine)
    aux_arr = np.array(aux)
    prediction = naive_bayes_model.predict(aux_arr)
    if prediction != label:
        img_misclasate.append(imagine)
        labels_for_print.append((label, prediction[0]))
        cnt_misclasate += 1
    if cnt_misclasate == 10:
        break

# for imagine, tuplu in zip(img_misclasate, labels_for_print):
#     image = np.reshape(imagine, (28, 28))
#     print(f"Imaginea este {tuplu[0]}, dar a fost misclasata ca fiind {tuplu[1]}")
#     plt.imshow(image.astype(np.uint8), cmap='gray')
#     plt.show()

print(confusion_matrix(test_labels, naive_bayes_model.predict(test_images_discretizata)).T)






