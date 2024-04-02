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
    d = float((b - a))/float((2**params["lungime_cromozom"]))
    params.update({"interval_discretizare": d})
    return params

def genereazaPopulatieInitiala():
    global params
    pas = 1/(10 ** params["precizie_interval"])
    numere_din_interval = []
    x = params["capete_interval"]["st"]
    while x <= params["capete_interval"]["dr"]:
        numere_din_interval.append(x)
        x += pas
    pop = np.random.choice(numere_din_interval, params["nr_cromozomi"])
    return [round(x, params["precizie_interval"]) for x in pop]

def cromozomToNumar(cromozom):
    #transform cromozomul intr-un numar
    def binStringToNumber(str):
        nr = 0
        for pow, i in enumerate(range(len(str) - 1, -1, -1)):
            if str[i] == '1':
                nr += 2**pow
        return nr
    #din cromozom aflu numarul asociat (al x lea interval)
    return round(params["capete_interval"]["st"] + binStringToNumber(cromozom) * params["interval_discretizare"], params["precizie_interval"])

def numarToCromozom(numar):
    #transform numarul intr-un cromozom
    #numarul a apartine al n - lea interval, iar n este codificat in binar
    a = params["capete_interval"]["st"]
    d = params["interval_discretizare"]
    l = params["lungime_cromozom"]
    intervalNr = math.floor((numar - a)/d)
    rezultat = bin(intervalNr)[2:]
    rezultatReturnat = "0"*(l - len(rezultat)) + rezultat
    return rezultatReturnat

def selectiePopulatie(pop):#imi este returnata populatia selectata si elementul elitist separat
    #selectia se va face si cu pastrarea celui mai bun cromozom
    def cautareBinara(lista, elem):
        st = 0
        dr = len(lista) - 1
        while st <= dr:
            m = (st + dr)//2
            if lista[m] == elem:
                return m
            if elem < lista[m]:
                dr = m - 1
            else:
                st = m + 1
        while elem < lista[m] and m >= 0:
            m -= 1
        while elem > lista[m] and m <= len(lista) - 1:
            m += 1
        return max(0, m)

    global params
    def f(x):
        return params["coeficienti"]["a"]*(x * x) + params["coeficienti"]["b"] * x + params["coeficienti"]["c"]

    F = sum([f(x) for x in pop])

    global file
    file.write("Populatia initiala\n")
    for i, elem in enumerate(pop):
        file.write(f"{i + 1}: {numarToCromozom(elem)} x= {elem} f= {f(elem)}\n")
    file.write("\n")

    probabilitati = [f(x)/F for x in pop]

    file.write("Probabilitati selectie\n")
    for i, prob in enumerate(probabilitati):
        file.write(f"cromozom {i + 1} probabilitate {prob}\n")


    maxim = max(pop, key = lambda x: f(x)/F)
    index_maxim = pop.index(maxim)
    #pop.pop(index_maxim)
    elem_elitist = pop[index_maxim]
    
    intervale_selectie = []
    interval_selectie_cautare = []
    st = 0
    for prob in probabilitati:
        interval_selectie_cautare.append(st + prob)
        intervale_selectie.append((st, st + prob))
        st += prob

    file.write("Intervale probabilitati de selectie\n")
    for i, prob in enumerate(intervale_selectie):
        file.write(f"{prob} ")
        if (i + 1) % 3 == 0:
            file.write("\n")
    file.write("\n")

    populatie_selectata = []
    for _ in range(params["nr_cromozomi"] - 1):
        u = np.random.uniform()
        pos = cautareBinara(interval_selectie_cautare, u)
        populatie_selectata.append(pop[pos])
        file.write(f"u={u} selectam cromozomul {pos}\n")

    file.write("Dupa selectie:\n")
    for i, elem in enumerate(populatie_selectata):
        file.write(f"{i + 1}: {numarToCromozom(elem)} x= {elem} f= {f(elem)}\n")
    file.write("\n\n")

    return populatie_selectata, elem_elitist

def incrucisarePopulatie(pop):
    global params
    def f(x):
        return params["coeficienti"]["a"]*(x * x) + params["coeficienti"]["b"] * x + params["coeficienti"]["c"]

    def incrucisareXY(x0, x1, i):
        aux = x0
        sir1 = x0[:i] + x1[i:]
        sir2 = x1[:i] + aux[i:]
        return sir1, sir2

    populatie_cromozomi = [numarToCromozom(nr) for nr in pop]
    cromozomi_marcati_incrucisare = []
    #punct_rupere = int(np.random.choice(list(range(1, params["lungime_cromozom"])))) de aici l am mutat mai jos pentru ca se schimba la fiecare crossover
    populatie_noua = []
    file.write(f"Probabilitatea de incrucisare {params['probabilitate_crossover']}\n")
    q = 0
    for cromozom in populatie_cromozomi:
        u = np.random.uniform()
        participaSauNU = ""
        if u < params["probabilitate_crossover"]:
            cromozomi_marcati_incrucisare.append(cromozom)
            participaSauNU = "< " + str(params["probabilitate_crossover"]) + " participa"
        else:
            populatie_noua.append(cromozom)
        q += 1
        file.write(f"{q}: {cromozom} u={u} {participaSauNU}\n")

    perechi_cromozomi = []
    if len(cromozomi_marcati_incrucisare) <= 1:
        return populatie_cromozomi
    if len(cromozomi_marcati_incrucisare) % 2 == 0:
        for i in range(0, len(cromozomi_marcati_incrucisare) - 1, 2):
            perechi_cromozomi.append([cromozomi_marcati_incrucisare[i], cromozomi_marcati_incrucisare[i + 1]])
    else:
        aux = cromozomi_marcati_incrucisare[:-1]
        cromozom_extra = cromozomi_marcati_incrucisare[-1]
        for i in range(0, len(aux) - 1, 2):
            perechi_cromozomi.append([aux[i], aux[i + 1]])
        perechi_cromozomi[-1].append(cromozom_extra)

    for pereche in perechi_cromozomi:
        punct_rupere = int(np.random.choice(list(range(1, params["lungime_cromozom"]))))
        if(len(pereche) == 2):
            file.write(f"Recombinare dintre cromozomii {pereche[0]} {pereche[1]} punct {punct_rupere}\n")
            crom1, crom2 = incrucisareXY(pereche[0], pereche[1], punct_rupere)
            populatie_noua.append(crom1)
            populatie_noua.append(crom2)
            file.write(f"Rezultat {crom1} {crom2}\n")
        else:
            file.write(f"Recombinare dintre cromozomii {pereche[0]} {pereche[1]} {pereche[2]} punct {punct_rupere}\n")
            crom1 = incrucisareXY(pereche[0], pereche[1], punct_rupere)[0]
            crom2 = incrucisareXY(pereche[0], pereche[2], punct_rupere)[0]
            crom3 = incrucisareXY(pereche[1], pereche[2], punct_rupere)[0]
            populatie_noua.append(crom1)
            populatie_noua.append(crom2)
            populatie_noua.append(crom3)
            file.write(f"Rezultat {crom1} {crom2} {crom3}\n")

    file.write(f"Dupa recombinare:\n")
    global elem_elitist
    populatie_noua.append(numarToCromozom(elem_elitist))
    for i, crom in enumerate(populatie_noua):
        file.write(f"{i + 1}: {crom} x= {cromozomToNumar(crom)} f={f(cromozomToNumar(crom))}\n")
    populatie_noua.pop()
    file.write("\n")

    return populatie_noua

def mutatiePopulatie(pop):
    global params
    def f(x):
        return params["coeficienti"]["a"]*(x * x) + params["coeficienti"]["b"] * x + params["coeficienti"]["c"]

    file.write(f"Probabilitate de mutatie pentru fiecare gena{params['probabilitate_mutatie']}\n")
    cromozomi_mutati = []
    q = 1
    selectati = []
    for crom in pop:
        aux = ""
        for j in range(len(crom)):
            u = np.random.uniform()
            if u < params["probabilitate_mutatie"]:
                selectati.append(q)
                if crom[j] == '1':
                    aux = aux + '0'
                else:
                    aux = aux + '1'
            else:
                aux = aux + crom[j]
        cromozomi_mutati.append(aux)
        q += 1
    file.write("Au fost selectati cromozomii:\n")
    for i in selectati:
        file.write(f"{i}\n")
    file.write("Dupa mutatie: \n")
    
    cromozomi_mutati.append(numarToCromozom(elem_elitist))
    for i, crom in enumerate(cromozomi_mutati):
        file.write(f"{i + 1}: {crom} x= {cromozomToNumar(crom)} f= {f(cromozomToNumar(crom))}\n")
    file.write("\n")
    cromozomi_mutati.pop()

    return cromozomi_mutati


file = open("output.txt", "w")

params = dict()
params = readInput("input.txt")
etape = params["etape"]
nr_etapa = 0

populatie_actuala = genereazaPopulatieInitiala()
aux1 = populatie_actuala

maxim = []

while nr_etapa <= etape:
    populatie_intermediara1, elem_elitist = selectiePopulatie(populatie_actuala)
    populatie_intermediara2_cromozomi = incrucisarePopulatie(populatie_intermediara1)
    aux = mutatiePopulatie(populatie_intermediara2_cromozomi)
    populatie_viitoare = [cromozomToNumar(x) for x in aux]
    populatie_viitoare.append(elem_elitist)
    #adaugam la populatie_viitoare elementele elitiste
    populatie_actuala = populatie_viitoare
    nr_etapa += 1
    maxim.append(elem_elitist)
    file.write("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")


file.write("Evolutia maximului:\n")
def f(x):
    return params["coeficienti"]["a"]*(x**2) + params["coeficienti"]["b"]*x + params["coeficienti"]["c"]
for elem in maxim:
    file.write(f"{f(elem)}\n")
    