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
normalized_images = 

print(sum_b)
print(sum_c)
print(images.shape)
print(index_suma_maxima)

io.imshow(mean_image.astype(np.uint8))
io.show()










