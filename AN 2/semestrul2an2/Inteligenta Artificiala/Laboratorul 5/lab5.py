import copy
import os

class NodArbore:
    def __init__(self, informatie, g=0, h=0, parinte=None):
        self.informatie = informatie
        self.parinte = parinte
        self.g=g
        self.h=h
        self.f=g+h

    def drumRadacina(self):
        nod=self
        l=[]
        while nod:
            l.append(nod)
            nod=nod.parinte
        return l[::-1]

    def inDrum(self,infonod):
        nod=self
        while nod:
            if nod.informatie==infonod:
                return True
            nod=nod.parinte
        return False

    def __eq__(self, other):
        return self.f==other.f and self.g==other.g

    def __lt__(self, other):
        return self.f<other.f or (self.f==other.f and self.h<other.h)

    def __str__(self):
        return  f"({self.informatie}, g:{self.g} f:{self.f})"

    #c (a->b->c)
    def __repr__(self):
        return f"{self.informatie}, ({'->'.join([str(x) for x in self.drumRadacina()])})"

class Graf:
    def __init__(self, start, scopuri):
        self.start=start
        self.scopuri=scopuri

    def valideaza(self):
        matriceDesfasuratata = self.start[0] + self.start[1] + self.start[2]
        nrInversiuni = 0
        for i, placuta in enumerate(matriceDesfasuratata):
            for placuta2 in matriceDesfasuratata[i + 1: ]:
                if placuta > placuta2 and placuta2 != 0:
                    nrInversiuni += 1
        return (nrInversiuni % 2 == 0)


    def scop(self, informatieNod):
        return informatieNod in self.scopuri

    def estimeaza_h(self,infoNod, euristica):
        if self.scop(infoNod):
            return 0
        if euristica=="banala":
            return 1
        if euristica=="euristica mutari":
            minH=float('inf')
            for scop in self.scopuri:
                h=0
                for iStiva,stiva in enumerate(scop):
                    for iBloc, bloc in enumerate(stiva):
                        try:
                            if infoNod[iStiva][iBloc]!=bloc:
                                h+=1
                        except:
                            h+=1 #aici poate sa vina si distanta manhatten pentru o alta euristica
                if h<minH:
                    minH=h
            return minH

    def succesori(self, nod, euristica):
        def gasesteGol(matr):
            for l in range(3):
                for c in range(3):
                    if matr[l][c] == 0:
                        return l, c

        
        lSuccesori=[]
        lGol, cGol = gasesteGol(nod.informatie)
        directii = [[1, 0], [0, 1], [-1, 0], [0, -1]]
        for d in directii:
            lPlacuta = lGol + d[0]
            cPlacuta = cGol + d[1]
            if not (0 <= lPlacuta <= 2 and 0 <= cPlacuta <= 2):
                continue
            infoSuccesor = copy.deepcopy(nod.informatie)
            infoSuccesor[lGol][cGol], infoSuccesor[lPlacuta][cPlacuta] = infoSuccesor[lPlacuta][cPlacuta], infoSuccesor[lGol][cGol]

                # if not nod.inDrum(infoSuccesor):
                #     lSuccesori.append(NodArbore(infoSuccesor, nod.g+ 1, self.estimeaza_h(infoSuccesor, euristica), nod))
        return lSuccesori




def aStarSolMultiple(gr, nsol, euristica):
    if not gr.valideaza():
        print("Nu are solutii")
        return
    coada=[NodArbore(gr.start)]
    while coada:
        nodCurent=coada.pop(0)
        if gr.scop(nodCurent.informatie):
            print(repr(nodCurent))
            nsol-=1
            if nsol==0:
                return
        coada+=gr.succesori(nodCurent, euristica)
        coada.sort()

def aStar(gr, euristica):
    OPEN=[NodArbore(gr.start)]
    CLOSED=[]
    while OPEN:
        nodCurent=OPEN.pop(0)
        CLOSED.append(nodCurent)
        if gr.scop(nodCurent.informatie):
            print(repr(nodCurent))
            return
        lSuccesori=gr.succesori(nodCurent, euristica)
        for s in lSuccesori:
            gasitOpen=False
            for nodC in OPEN:
                if s.informatie==nodC.informatie:
                    gasitOpen=True
                    if s<nodC:
                        OPEN.remove(nodC)
                    else:
                        lSuccesori.remove(s)
                    break
            if not gasitOpen:
                for nodC in CLOSED:
                    if s.informatie == nodC.informatie:
                        if s < nodC:
                            CLOSED.remove(nodC)
                        else:
                            lSuccesori.remove(s)
                        break

        OPEN+=lSuccesori
        OPEN.sort()




here = os.path.dirname(os.path.abspath(__file__))
filename = os.path.join(here, 'input.txt')
f=open(filename, "r")
continut = f.read()
start = [list(map(int, linie.strip().split())) for linie in continut.strip().split('\n')]
# print(start)
# print(scopuri)
scopuri = [
    [[1,2,3],
    [4,5,6],
    [7,8,0]]
]

gr=Graf(start,scopuri)
aStarSolMultiple(gr, 1, "euristica mutari")