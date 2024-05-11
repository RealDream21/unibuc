def stangaSauDreapta(xp, yp, xq, yq, xr, yr):
    det = xq * yr + xr * yp + xp * yq - xq * yp - xr * yq - xp * yr
    return det

n = int(input().strip())
puncte = []
virajStanga = 0
virajDreapta = 0
virajTouch = 0

for _ in range(n):
    tuplu = (x, y) = [int(x) for x in input().strip().split()]
    puncte.append(tuplu)

for i, punct in enumerate(puncte):
    if(i == 0):
        continue
    xp, yp = puncte[i - 1]
    xq, yq = puncte[i]
    xr, yr = puncte[(i + 1) % n]
    directie = stangaSauDreapta(xp, yp, xq, yq, xr, yr)
    if(directie < 0):
        virajDreapta += 1
    if(directie > 0):
        virajStanga += 1
    if(directie == 0):
        virajTouch += 1
    
print(f"{virajStanga} {virajDreapta} {virajTouch}")
