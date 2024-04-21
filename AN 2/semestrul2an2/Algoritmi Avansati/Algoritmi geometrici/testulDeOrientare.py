t = int(input().strip())


def stangaSauDreapta(xp, yp, xq, yq, xr, yr):
    det = xq * yr + xr * yp + xp * yq - xq * yp - xr * yq - xp * yr
    return det

while t:
    xp, yp, xq, yq, xr, yr = [int(x) for x in input().strip().split()]
    orientare = stangaSauDreapta(xp, yp, xq, yq, xr, yr)
    if(orientare < 0):
        print("RIGHT")
    elif(orientare > 0):
        print("LEFT")
    elif(orientare == 0):
        print("TOUCH")
    t -= 1

input()