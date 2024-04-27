from matplotlib import pyplot as plt 
from random import randint


def stangaSauDreapta(xp, yp, xq, yq, xr, yr):
    det = xq * yr + xr * yp + xp * yq - xq * yp - xr * yq - xp * yr
    return det

# n = int(input().strip())
n = randint(10, 30)

puncte = []

for _ in range(n):
    punct = (x, y) = [randint(0, 50), randint(0, 50)]
    puncte.append(punct)
#
puncte_salvate = puncte.copy()
#

puncte.sort(key=lambda x: (x[0], x[1]))

frontiera_jos = []
frontiera_jos.append(puncte[0])
frontiera_jos.append(puncte[1])
for punct in puncte[2:]:
    frontiera_jos.append(punct)
    while len(frontiera_jos) > 2 and not (stangaSauDreapta(frontiera_jos[-3][0], frontiera_jos[-3][1], frontiera_jos[-2][0], frontiera_jos[-2][1], frontiera_jos[-1][0], frontiera_jos[-1][1]) > 0):
        frontiera_jos.pop(len(frontiera_jos) - 2)

frontiera_sus = []
frontiera_sus.append(puncte[0])
frontiera_sus.append(puncte[1])
for punct in puncte[2:]:
    frontiera_sus.append(punct)
    while len(frontiera_sus) > 2 and not (stangaSauDreapta(frontiera_sus[-3][0], frontiera_sus[-3][1], frontiera_sus[-2][0], frontiera_sus[-2][1], frontiera_sus[-1][0], frontiera_sus[-1][1]) < 0):
        frontiera_sus.pop(len(frontiera_sus) - 2)

# rez = frontiera_jos
for punct in reversed(frontiera_sus):
    if punct not in frontiera_jos:
        frontiera_jos.append(punct)

print(len(frontiera_jos))
for punct in frontiera_jos:
    print(f"{punct[0]} {punct[1]}")

xs, ys = zip(*puncte_salvate)
plt.scatter(xs, ys)
for i in range(1, len(frontiera_jos) + 1):
    if i == len(frontiera_jos): i = 0
    c0 = frontiera_jos[i - 1]
    c1 = frontiera_jos[i]
    plt.plot((c0[0], c1[0]), (c0[1], c1[1]), 'r')
plt.show()



