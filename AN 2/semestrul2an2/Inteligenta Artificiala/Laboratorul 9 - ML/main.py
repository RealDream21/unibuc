import numpy as np
import matplotlib.pyplot as plt


train_images = np.loadtxt('train_images.txt')
test_images = np.loadtxt('test_images.txt')
train_labels = np.loadtxt('train_labels.txt', 'int')
test_labels = np.loadtxt('test_labels.txt','int')

class KnnClassifier:
    def __init__(self, train_images, train_labels):
        self.train_images = train_images
        self.train_labels = train_labels

    def classify_image(self, test_image, num_neighbors=3, metric='l2'):
        if metric == 'l1':
            distante = np.sum(np.abs(self.train_images - test_image), axis = 1)
        elif metric == 'l2':
            distante = np.sqrt(np.sum(np.square(self.train_images - test_image), axis =1))

        dist_labels = [(distante[i], train_labels[i]) for i in range(len(distante))]
        dist_labels = sorted(dist_labels, key=lambda x:x[0])
        frecv_vec = [0 for _ in range(10)]
        nr = -1
        max_frecv = -1
        for vecin in dist_labels[:num_neighbors]:
            frecv_vec[vecin[1]] += 1
        for i in range(10):
            if frecv_vec[i] > max_frecv:
                nr = i
                max_frecv = frecv_vec[i]
        return nr


clasificator = KnnClassifier(train_images, train_labels)
clasif_corecta = 0
predictie = []
for imagine, label in zip(test_images, test_labels):
    cls = clasificator.classify_image(imagine)
    if cls == label:
        clasif_corecta += 1
    predictie.append(cls)
print(clasif_corecta/len(test_images))

file = open("predictii_3nn_l2_mnist.txt", "w")

for elem in predictie:
    file.write(f"{elem}\n")


file = open("acuratete_l2.txt", "w")
vecini = [1, 3, 5, 7, 9]
acuratete = []
for vecin in vecini:
    clasif_corecta = 0
    for imagine, label in zip(test_images, test_labels):
        cls = clasificator.classify_image(imagine, num_neighbors=vecin, metric='l2')
        if cls == label:
            clasif_corecta += 1
    acuratete.append(clasif_corecta/len(test_images))
    file.write(f"{clasif_corecta/len(test_images)}\n")

file.close()

print(acuratete)
plt.plot(vecini, acuratete)
plt.xlabel("number of neighbors")
plt.ylabel("accuracy")
plt.show()

acuratete = []
for vecin in vecini:
    clasif_corecta = 0
    for imagine, label in zip(test_images, test_labels):
        cls = clasificator.classify_image(imagine, num_neighbors=vecin, metric='l1')
        if cls == label:
            clasif_corecta += 1
    acuratete.append(clasif_corecta/len(test_images))

plt.plot(vecini, acuratete, label="l1")
acuratete_l2 = np.loadtxt("acuratete_l2.txt")
plt.plot(vecini, acuratete_l2, label = "l2")
plt.legend()
plt.show()

