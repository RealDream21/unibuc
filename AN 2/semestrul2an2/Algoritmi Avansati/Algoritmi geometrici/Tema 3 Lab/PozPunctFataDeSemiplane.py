def gaseste_intersectia(semiplan1, semiplan2):
    a1,b1,c1 = semiplan2
    a2,b2,c2 = semiplan1
    x = (c2*b1 - c1*b2) / (a1*b2 - a2*b1)
    y = (-1 * c1 - a1 * x) / b1
    return tuple([x, y])

puncte_to_semiplan = dict()

n = int(input())

semiplane_ox = []
semiplane_oy = []

for _ in range(n):
    semiplan = [int(x) for x in input().split()]
    if semiplan[0] == 0:
        semiplane_oy.append(tuple(semiplan))
    elif semiplan[1] == 0:
        semiplane_ox.append(tuple(semiplan))

m = int(input())
queries = []
for _ in range(m):
    queries.append(tuple([float(x) for x in input().split()]))

#print(semiplane_ox, semiplane_oy)

puncte_intersectie = []
for semiplan1 in semiplane_ox:
    for semiplan2 in semiplane_oy:
        #calculam intersectia
        punct = gaseste_intersectia(semiplan1, semiplan2)
        puncte_intersectie.append(punct)
        
def gaseste_semiplan_ox(punct):
    for semiplan in semiplane_ox:
        if semiplan[0] * punct[0] + semiplan[2] == 0:
            return semiplan

def gaseste_semiplan_oy(punct):
    for semiplan in semiplane_oy:
        if semiplan[1] * punct[1] + semiplan[2] == 0:
            return semiplan


def dreptunghi_valid(punct1, punct2):
    #de la punct1 semiplanele trebuie sa mearga in jos si in dreapta
    #de la punct2 semiplanele trebuie sa mearga in sus si in stanga
    #din coordonate putem extrage dreapta din care fac parte, daca ne folosim si de dictionar
    semiplan_ox_punct1 = gaseste_semiplan_ox(punct1)
    semiplan_oy_punct1 = gaseste_semiplan_oy(punct1)
    semiplan_ox_punct2 = gaseste_semiplan_ox(punct2)
    semiplan_oy_punct2 = gaseste_semiplan_oy(punct2)

    #print(semiplan_ox_punct1, semiplan_oy_punct1, semiplan_ox_punct2, semiplan_oy_punct2)
    if semiplan_ox_punct1[0] < 0 and semiplan_oy_punct1[1] > 0  and semiplan_ox_punct2[0] > 0 and semiplan_oy_punct2[1] < 0:
        return True
    return False

dreptunghiuri_interesante = []
puncte_intersectie = sorted(puncte_intersectie, key=lambda x:-x[1])
for i in range(len(puncte_intersectie)):
    for j in range(i + 1, len(puncte_intersectie)):
        punct1 = puncte_intersectie[i]#punct stanga sus
        punct2 = puncte_intersectie[j]#punct dreapta jos
        if dreptunghi_valid(punct1, punct2):
            dreptunghiuri_interesante.append([punct1, punct2])


def punct_in_dreptunghi(punct, dreptunghi):
    if punct[0] > dreptunghi[0][0] and punct[1] < dreptunghi[0][1] and punct[0] < dreptunghi[1][0] and punct[1] > dreptunghi[1][1]:
        return True
    return False

def arie(dreptunghi):
    return int((dreptunghi[1][0] - dreptunghi[0][0])*(dreptunghi[0][1] - dreptunghi[1][1]))


for punct in queries:
    min_area = 999999999
    for dreptunghi in dreptunghiuri_interesante:
        if punct_in_dreptunghi(punct, dreptunghi):
            if min_area > arie(dreptunghi):
                min_area = arie(dreptunghi)
    if min_area == 999999999:
        print("NO")
    else:
        print("YES")
        print(min_area)



