{
 "cells": [
  {
   "cell_type": "code",
   "execution_count": 132,
   "id": "6fe49e24-a823-4ef7-931a-3573073c3fbc",
   "metadata": {
    "tags": []
   },
   "outputs": [],
   "source": [
    "import numpy as np\n",
    "from tqdm import tqdm\n",
    "\n",
    "bug = \"BUG\"\n",
    "non_bug = \"NU_ARE_BUG\"\n",
    "positive = \"COD_NOT_OK\"\n",
    "negative = \"COD_OK\"\n",
    "\n",
    "def SIMULATORUL(p, labels):\n",
    "    if np.random.uniform() < p:\n",
    "        return labels[1]\n",
    "    return labels[0]\n",
    "\n",
    "def SIMULATORUL_ANALOG(p, labels):\n",
    "    return np.random.choice(labels, p = p)\n",
    "    \n",
    "def simuleaza_experimentatorul():\n",
    "    raspuns = []\n",
    "    raspuns.append(SIMULATORUL(0.05, labels=[non_bug, bug]))\n",
    "    \n",
    "    if raspuns[0] == bug:\n",
    "        raspuns.append(SIMULATORUL(0.95, labels = [negative, positive]))\n",
    "    elif raspuns[0] == non_bug:\n",
    "        raspuns.append(SIMULATORUL(0.98, labels=[positive, negative]))\n",
    "    return raspuns"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 134,
   "id": "f0e0e2fe-35d0-49d9-abc5-9a37826f34c1",
   "metadata": {
    "tags": []
   },
   "outputs": [],
   "source": [
    "simuleaza_experimentatorul()\n",
    "\n",
    "def rezolva_problema(nr_iteratii = 1000000):\n",
    "    simulari = [simuleaza_experimentatorul() for _ in range(nr_iteratii)]\n",
    "    cazuri_total = 0\n",
    "    cazuri_favorabile = 0\n",
    "    for sim in tqdm(simulari):\n",
    "        if sim[1] == negative:\n",
    "            cazuri_total += 1\n",
    "            if sim[0] == bug:\n",
    "                cazuri_favorabile += 1\n",
    "    print(cazuri_favorabile/cazuri_total)\n",
    "    "
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 136,
   "id": "12e1a41a-f0fd-484a-901b-3272e398dc65",
   "metadata": {
    "tags": []
   },
   "outputs": [
    {
     "name": "stderr",
     "output_type": "stream",
     "text": [
      "100%|███████████████████████████████████████████████████████████████████| 1000000/1000000 [00:00<00:00, 2427852.17it/s]\n"
     ]
    },
    {
     "name": "stdout",
     "output_type": "stream",
     "text": [
      "0.0027476851876639\n"
     ]
    }
   ],
   "source": [
    "rezolva_problema()"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 203,
   "id": "92785f28-1fa0-4ebf-bfa6-6588b343298f",
   "metadata": {
    "tags": []
   },
   "outputs": [],
   "source": [
    "def simuleaza_barbut():\n",
    "    return (np.random.randint(low=1, high=7, size=(2))).tolist()\n",
    "\n",
    "\n",
    "def rezolva_problema_a(nr_iteratii):\n",
    "    cazuri_favorabile = 0\n",
    "    for _ in tqdm(range(nr_iteratii)):\n",
    "        pereche = simuleaza_barbut()\n",
    "        if not sum(pereche) % 5:\n",
    "            cazuri_favorabile += 1\n",
    "            \n",
    "    print(cazuri_favorabile/nr_iteratii)\n",
    "    \n",
    "def rezolva_problema_b(nr_iteratii):\n",
    "    cazuri_favorabile = 0\n",
    "    cazuri_total = 0\n",
    "    for _ in range(nr_iteratii):\n",
    "        pereche = simuleaza_barbut()\n",
    "        if pereche[0] > 3:\n",
    "            cazuri_total += 1\n",
    "            if (pereche[0] + pereche[1]) % 3 == 0:\n",
    "                cazuri_favorabile += 1\n",
    "    print(cazuri_favorabile/cazuri_total)\n"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 207,
   "id": "2781230a-87e2-448a-93b0-ef98435ebcd3",
   "metadata": {
    "tags": []
   },
   "outputs": [
    {
     "name": "stdout",
     "output_type": "stream",
     "text": [
      "0.3340313092033104\n"
     ]
    }
   ],
   "source": [
    "rezolva_problema_b(20000)"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": null,
   "id": "c05d8760-1aa9-4b5a-888e-47695f7eaa8e",
   "metadata": {},
   "outputs": [],
   "source": []
  }
 ],
 "metadata": {
  "kernelspec": {
   "display_name": "Python 3 (ipykernel)",
   "language": "python",
   "name": "python3"
  },
  "language_info": {
   "codemirror_mode": {
    "name": "ipython",
    "version": 3
   },
   "file_extension": ".py",
   "mimetype": "text/x-python",
   "name": "python",
   "nbconvert_exporter": "python",
   "pygments_lexer": "ipython3",
   "version": "3.11.5"
  }
 },
 "nbformat": 4,
 "nbformat_minor": 5
}
