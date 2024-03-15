import queue

class NodArbore:
    def __init__(self, informatie, g = 0, h = 0, parinte = None):
        self.informatie = informatie
        self.parinte = parinte
        self.g = g
        self.h = h
        self.f = g + h

    def drumRadacina(self):
        nod = self
        lDrum = []
        while nod:
            lDrum.append(nod)
            nod = nod.parinte
        return lDrum[::-1]
    
    def inDrum(self, infonod):
        nod=self
        while nod:
            if nod.informatie == infonod:
                return True
            nod = nod.parinte
        return False
    
    def __eq__(self, other):
        return self.f == other.f
    def __lt__(self, other):
        return self.f < other.f or (self.f == other.f and self.g > other.g)
    
    
    def __str__(self):
        return f"({str(self.informatie)} g: {self.g} f:{self.f}"
    def __repr__(self):
        return  "{}, ({})".format(str(self.informatie), "->".join([str(x) for x in self.drumRadacina()]))


class Graf:
    def __init__(self, matr, start, scopuri, h):
        self.matr = matr
        self.start = start
        self.scopuri = scopuri
        self.h = h

    def scop(self, informatieNod):
        return informatieNod in self.scopuri
    
    def estimeaza_h(self, infoNod):
        return self.h[infoNod]

    def succesori(self, nod):
        lSuccesori = []
        for infoSuccesor in range(len(self.matr)):
            if self.matr[nod.informatie][infoSuccesor] > 0 and not nod.inDrum(infoSuccesor):
                lSuccesori.append(NodArbore(infoSuccesor, nod.g + self.matr[nod.informatie][infoSuccesor], self.estimeaza_h(infoSuccesor), nod))
        return lSuccesori

def breadthFirst(gr, nsol = 2):
    coada = queue.PriorityQueue()
    coada.put(NodArbore(gr.start))
    while coada:
        nodCurent = coada.get()
        if gr.scop(nodCurent.informatie):
            print(repr(nodCurent))
            nsol -= 1
            if nsol == 0:
                return
        for succ in gr.succesori(nodCurent):
            coada.put(succ)

m = [
[0, 3, 5, 10, 0, 0, 100],
[0, 0, 0, 4, 0, 0, 0],
[0, 0, 0, 4, 9, 3, 0],
[0, 3, 0, 0, 2, 0, 0],
[0, 0, 0, 0, 0, 0, 0],
[0, 0, 0, 0, 4, 0, 5],
[0, 0, 3, 0, 0, 0, 0],
]
start = 0
scopuri = [4,6]
h=[0,1,6,2,0,3,0]



gr = Graf(m, start, scopuri, h)
breadthFirst(gr, nsol=6)


#TEMA DEPTH FIRSTx