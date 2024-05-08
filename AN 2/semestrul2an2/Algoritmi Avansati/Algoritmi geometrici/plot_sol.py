from matplotlib import pyplot as plt 


file = open("teste/stelat8.in")
n = int(file.readline())
puncte = []
linii_fisier = file.readlines()
for linie in linii_fisier:
    puncte.append([int(x) for x in linie.strip().split()])

file = open("teste/stelat8.out")
n_solutie = file.readline()
puncte_solutie = []
linii_fisier = file.readlines()
for linie in linii_fisier:
    puncte_solutie.append([int(x) for x in linie.strip().split()])

xs, ys = zip(*puncte)
plt.scatter(xs, ys)
for i in range(1, len(puncte_solutie) + 1):
    if i == len(puncte_solutie): i = 0
    c0 = puncte_solutie[i - 1]
    c1 = puncte_solutie[i]
    plt.plot((c0[0], c1[0]), (c0[1], c1[1]), 'r')


plt.show()