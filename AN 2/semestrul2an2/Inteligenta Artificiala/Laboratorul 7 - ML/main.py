import numpy as np
import os
from skimage import io


here = os.getcwd()

image_folder = os.path.join(here, 'images')

raw_images = []

for image_id in range(9):
    image_name = "car_" + str(image_id) + ".npy"
    image_np = np.load(image_folder + "/" + image_name)
    raw_images.append(image_np)

images = np.array(raw_images)
sum_b = np.sum(images)
sum_c = np.sum(images, axis = (1, 2))
index_suma_maxima = np.argmax(sum_c, axis = 0)
mean_image = np.mean(images, axis=0)
imgs_std = np.std(images, axis=(0,1,2))

print(sum_b)
print(sum_c)
print(images.shape)
print(index_suma_maxima)

imagini_normalizate = []
for imagine in images:
    aux_imagine = np.copy(imagine)
    aux_imagine = np.subtract(aux_imagine, mean_image)
    aux_imagine = np.divide(aux_imagine, imgs_std)
    imagini_normalizate.append(aux_imagine)

imagini_normalizate_np =  np.array(imagini_normalizate)
print(imagini_normalizate_np.shape)

imagini_decupate = []
for imagine in images:
    copie_imagine = np.copy(imagine[200:300, 280:400])
    imagini_decupate.append(copie_imagine)

imagini_decupate_np = np.array(imagini_decupate)
print(imagini_decupate_np.shape)

io.imshow(imagini_decupate_np[0].astype(np.uint8))
io.show()
io.imshow(mean_image.astype(np.uint8))
io.show()
