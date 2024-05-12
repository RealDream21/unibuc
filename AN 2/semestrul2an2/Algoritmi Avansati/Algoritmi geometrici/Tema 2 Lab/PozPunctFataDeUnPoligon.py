n = int(input())
puncte = []
for _ in range(n):
    puncte.append([int(x) for x in input().strip().split()])

k = int(input())
queries = []
for _ in range(k):
    queries.append([int(x) for x in input().strip().split()])

el_max = max(puncte, key=lambda x: x[1])
m = [el_max[0], el_max[1]]
m[0] = m[0]*3
m[1] = m[1]*7

def stangaSauDreapta(A, B, C):
    xp, yp = A
    xq, yq = B 
    xr, yr = C
    det = xq * yr + xr * yp + xp * yq - xq * yp - xr * yq - xp * yr
    return det

def semn(x):
    if(x < 0):
        return -1
    else:
        return 1

def pozitieSegmente(m, q, p1, p2):
    #daca(AB) SI (CD) se intersecteaza in interior daca si numai daca A SI B de o parte a CD si C si D de o parte AB
    if((stangaSauDreapta(p1, p2, q) == 0)):
        min_x = min(p1, p2, key=lambda x : x[0])[0]
        max_x = max(p1, p2, key= lambda x: x[0])[0]
        min_y = min(p1, p2, key=lambda x : x[1])[1]
        max_y = max(p1, p2, key= lambda x: x[1])[1]
        if q[0] >= min_x and q[0] <= max_x and q[1] >= min_y and q[1] <= max_y:
            return "PE_SEGMENT"

    if((semn(stangaSauDreapta(p1, p2, m)) != semn(stangaSauDreapta(p1, p2, q))) and (semn(stangaSauDreapta(m, q, p1)) != semn(stangaSauDreapta(m, q, p2)))):
        if(stangaSauDreapta(p1, p2, q) == 0):
            return "PE_SEGMENT"
        return "INTERSECTIE"
    else:
        return "NU_INTERSECTIE"

def inauntru(puncte, punct_test):
    cnt = 0
    for i in range(len(puncte)):
        p1 = puncte[i]
        p2 = puncte[(i + 1)%(len(puncte))]
        pos = pozitieSegmente(m, punct_test, p1, p2)
        if(pos == "INTERSECTIE"):
            cnt += 1
        if(pos == "PE_SEGMENT"):
            return "BOUNDARY"
    if (cnt % 2 == 1):
        return "INSIDE"
    return "OUTSIDE"

for punct_test in queries:
    print(inauntru(puncte, punct_test))
    