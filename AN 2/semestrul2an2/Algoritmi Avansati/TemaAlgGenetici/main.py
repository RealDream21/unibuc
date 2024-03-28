import os
import numpy as np
import math

def readInput(filename_):
    params = dict()
    here = os.path.dirname(os.path.abspath(__file__))
    filename = os.path.join(here, filename_)
    f = open(filename, "r")
    text = f.read().strip().split('\n')
    for param in text:
        left, right = param.split('=')
        if left not in params.keys():
            left = left.strip()
            if left == "probabilitate_crossover" or left == "probabilitate_mutatie":
                params.update({left: float(right)})
            elif left == "coeficienti":
                a, b, c = [int(x) for x in right.strip().split()]
                aux = dict()
                aux.update({"a" : a})
                aux.update({"b": b})
                aux.update({"c": c})
                params.update({left: aux})
            elif left == "capete_interval":
                aux = dict()
                a, b = right.strip().split()
                aux.update({"st": float(a)})
                aux.update({"dr": float(b)})
                params.update({left: aux})
            else:
                params.update({left: int(right)})

    a = params["capete_interval"]["st"]
    b = params["capete_interval"]["dr"]
    p = params["precizie_interval"]
    params.update({"lungime_cromozom": math.ceil(math.log(float((b - a))*float((10**p)), 2))})
    d = float((b - a))/float((2**params["l"]))
    params.update({"interval_discretizare": d})
    return params

def genereazaPopulatieInitiala():
    global params
    pas = 1/(10 ** params["precizie_interval"])
    print(params)
    numere_din_interval = []
    x = params["capete_interval"]["st"]
    while x <= params["capete_interval"]["dr"]:
        numere_din_interval.append(x)
        x += pas
    pop = np.random.choice(numere_din_interval, params["nr_cromozomi"])
    print(pop)
    return pop

def cromozomToNumarInterval(cromozom):
    def binStringToNumber(str):
        nr = 0
        for pow, i in enumerate(range(len(str) - 1, -1, -1)):
            if str[i] == '1':
                nr += 2**pow
        return nr
    return params["capete_interval"]["st"] + binStringToNumber(cromozom) * params["interval_discretizare"]

def numarIntervalToCromozom(numar):
    a = params["capete_interval"]["st"]
    d = params["interval_discretizare"]
    l = params["lungime_cromozom"]
    intervalNr = math.floor((numar - a)/d)
    rezultat = bin(intervalNr)[2:]
    rezultatReturnat = "0"*(l - len(rezultat)) + rezultat
    return rezultatReturnat

def selectiePopulatie(pop):
    pass

def incrucisarePopulatie(pop):
    pass

def mutatiePopulatie(pop):
    pass



params = dict()
params = readInput("input.txt")
etape = params["etape"]
nr_etapa = 0

print(params)

populatie_actuala = genereazaPopulatieInitiala()
while nr_etapa <= etape:
    populatie_intermediara1 = selectiePopulatie(populatie_actuala)
    populatie_intermediara2 = incrucisarePopulatie(populatie_intermediara1)
    populatie_viitoare = mutatiePopulatie(populatie_intermediara2)
    #adaugam la populatie_viitoare elementele elitiste
    populatie_actuala = populatie_viitoare
    nr_etapa += 1