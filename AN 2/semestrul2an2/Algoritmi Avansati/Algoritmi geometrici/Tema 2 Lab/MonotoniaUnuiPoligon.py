n = int(input())

puncte = []
for _ in range(n):
    puncte.append([int(x) for x in input().split()])

cel_mai_din_stanga = min(puncte, key= lambda x:x[0])
cel_mai_din_dreapta = max(puncte, key= lambda x:x[0])
cel_mai_de_sus = max(puncte, key= lambda x:x[1])
cel_mai_de_jos = min(puncte, key= lambda x:x[1])

def semn(a):
    if a < 0:
        return -1
    else:
        return 1

def x_monoton():
    drum_1 = []
    drum_2 = []
    n = len(puncte)
    i = 0
    while True:#calculam drumul de jos
        if puncte[i] == cel_mai_din_stanga:
            drum_1.append(puncte[i])
        elif len(drum_1) != 0:
            drum_1.append(puncte[i])
        if puncte[i] == cel_mai_din_dreapta and len(drum_1) != 0:
            break
        i = (i + 1) % n

    i -= 1
    while True:#calculam drumul de sus
        if puncte[i] == cel_mai_din_dreapta:
            drum_2.append(puncte[i])
        elif len(drum_2) != 0:
            drum_2.append(puncte[i])
        if puncte[i] == cel_mai_din_stanga and len(drum_2) != 0:
            break
        i = (i + 1) % n

    diferente_drum_1 = []
    diferente_drum_2 = []
    for i in range(len(drum_1) - 1):
        diferente_drum_1.append(drum_1[i + 1][0] - drum_1[i][0])
    for i in range(len(drum_2) - 1):
        diferente_drum_2.append(drum_2[i + 1][0] - drum_2[i][0])

    for i in range(len(diferente_drum_1) - 1):
        if semn(diferente_drum_1[i + 1]) != semn(diferente_drum_1[i]):
            print(diferente_drum_1[i + 1], diferente_drum_1[i], drum_1[i + 1], drum_1[i])
            return "NO"
    for i in range(len(diferente_drum_2) - 1):
        if(semn(diferente_drum_2[i + 1]) != semn(diferente_drum_2[i])):
            return "NO"
    return "YES"

def y_monoton():
    drum_1 = []
    drum_2 = []
    n = len(puncte)
    i = 0
    while True:#calculam drumul din stanga
        if puncte[i] == cel_mai_de_sus:
            drum_1.append(puncte[i])
        elif len(drum_1) != 0:
            drum_1.append(puncte[i])
        if puncte[i] == cel_mai_de_jos and len(drum_1) != 0:
            break
        i += 1
        i = i % n

    #i -= 1
    while True:#calculam drumul din dreapta
        if puncte[i] == cel_mai_de_jos:
            drum_2.append(puncte[i])
        elif len(drum_2) != 0:
            drum_2.append(puncte[i])
        if puncte[i] == cel_mai_de_sus and len(drum_2) != 0:
            break
        i += 1
        i = i % n

    diferente_drum_1 = []
    diferente_drum_2 = []
    for i in range(len(drum_1) - 1):
        diferente_drum_1.append(drum_1[i + 1][1] - drum_1[i][1])
    for i in range(len(drum_2) - 1):
        diferente_drum_2.append(drum_2[i + 1][1] - drum_2[i][1])

    for i in range(len(diferente_drum_1) - 1):
        if semn(diferente_drum_1[i + 1]) != semn(diferente_drum_1[i]):
            return "NO"
    for i in range(len(diferente_drum_2) - 1):
        if(semn(diferente_drum_2[i + 1]) != semn(diferente_drum_2[i])):
            return "NO"
    return "YES"


print(x_monoton())
print(y_monoton())