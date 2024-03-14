import math

def solveTo():
    global a, b, l, d
    xi = float(input().strip())
    intervalNr = math.floor((xi - a)/d)
    rezultat = bin(intervalNr)[2:]
    rezultatReturnat = "0"*(l - len(rezultat)) + rezultat
    return rezultatReturnat

def solveFrom():
    def binStringToNumber(str):
        nr = 0
        for pow, i in enumerate(range(len(str) - 1, -1, -1)):
            if str[i] == '1':
                nr += 2**pow
        return nr

    global a, b, l, d
    bi = input().strip()
    aux = bi
    return a + binStringToNumber(aux)*d


a, b = [float(x) for x in input().strip().split()]
p = int(input().strip())
m = int(input().strip())

l = math.ceil(math.log(float((b - a))*float((10**p)), 2))
d = float((b - a))/float((2**l))

while m:
    task = input().strip()
    if task == "TO":
        print(solveTo())
    elif task == "FROM":
        print(solveFrom())
    m -= 1