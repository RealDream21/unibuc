import os
import numpy as np

here = os.getcwd()
here = os.path.join(here, 'evaluare')
here = os.path.join(here, 'fisiere_solutie')
here = os.path.join(here, '331_Alexe_Bogdan')
here = os.path.join(here, 'task1')
print(here)

file = np.load(os.path.join(here, 'scores_all_faces.npy'))

print(file.shape)