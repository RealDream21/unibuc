from math import sqrt

def cross_product(p0, pi, q):
    A = [pi[0] - p0[0], pi[1] - p0[1]]
    B = [q[0] - p0[0], q[1] - p0[1]]
    return A[0]*B[1] - B[0]*A[1]

def stangaSauDreapta(xp, yp, xq, yq, xr, yr):
    det = xq * yr + xr * yp + xp * yq - xq * yp - xr * yq - xp * yr
    return det

def distanta(a, b):
    return sqrt((a[0] - b[0]) ** 2 + (a[1] - b[1]) ** 2)

def semn(a):
    if(a >= 0):
        return 1
    else:
        return -1

n = int(input())

puncte = []
for _ in range(n):
    puncte.append([int(x) for x in input().split()])

k = int(input())
queries = []
for _ in range(k):
    queries.append([int(x) for x in input().split()])

p0 = min(puncte, key = lambda x:(x[0], -x[1]))
p0_index = puncte.index(p0)
puncte = puncte[p0_index:] + puncte[:p0_index]


def rezolva(punct_test):
    xp, yp = puncte[-1]
    xq, yq = puncte[0]
    xr, yr = punct_test

    if(stangaSauDreapta(xp, yp, xq, yq, xr, yr) < 0):
        return "OUTSIDE"
    if(distanta(puncte[-1], punct_test) + distanta(punct_test, puncte[0]) == distanta(puncte[-1], puncte[0])):
        return "BOUNDARY"
    
    xp, yp = puncte[0]
    xq, yq = puncte[1]
    xr, yr = punct_test

    if(stangaSauDreapta(xp, yp, xq, yq, xr, yr) < 0):
        return "OUTSIDE"
    if(distanta(puncte[0], punct_test) + distanta(punct_test, puncte[1]) == distanta(puncte[0], puncte[1])):
        return "BOUNDARY"
    

    def gaseste_indice_pi(punct_test):
        st = 0
        dr = len(puncte) - 1
        while dr - st > 1:
            m = (st + dr)//2
            if cross_product(p0, puncte[m], punct_test) >= 0:
                st = m
            else:
                dr = m
        return st
    
    i = gaseste_indice_pi(punct_test)
    sgn = cross_product(puncte[i], puncte[i + 1], punct_test)
    if(sgn < 0):
        return "OUTSIDE"
    elif (sgn > 0):
        return "INSIDE"
    elif (sgn == 0):
        return "BOUNDARY"

    
for punct_test in queries:
    print(rezolva(punct_test))