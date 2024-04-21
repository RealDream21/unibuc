def stangaSauDreapta(xp, yp, xq, yq, xr, yr):
    det = xq * yr + xr * yp + xp * yq - xq * yp - xr * yq - xp * yr
    return det

n = int(input().strip())

puncte = []

for _ in range(n):
    punct = (x, y) = [int(x) for x in input().split()]
    puncte.append(punct)

puncte.sort(key=lambda x: x[0])

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
    while len(frontiera_sus) > 2 and stangaSauDreapta(frontiera_sus[-3][0], frontiera_sus[-3][1], frontiera_sus[-2][0], frontiera_sus[-2][1], frontiera_sus[-1][0], frontiera_sus[-1][1]) >= 0:
        frontiera_sus.pop(len(frontiera_sus) - 2)


rez = frontiera_jos
for punct in frontiera_sus:
    if punct not in rez:
        rez.append(punct)
print(rez)
    

