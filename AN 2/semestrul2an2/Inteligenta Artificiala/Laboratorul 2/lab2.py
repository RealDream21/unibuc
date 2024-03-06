class NodArbore:
    def __init__(self, informatie, parinte = None):
        self.informatie = informatie
        self.parinte = parinte

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
    
    def __str__(self):
        return str(self.informatie)
    def __repr__(self):
        return  "{}, ({})".format(str(self.informatie), "->".join([str(x) for x in self.drumRadacina()]))


class Graf:
    def __init__(self, start, scopuri):
        self.start = start
        self.scopuri = scopuri

    def scop(self, informatieNod):
        return informatieNod in self.scopuri
    
    #mal curent = malul cu barca
    def succesori(self, nod):
        def testConditie(m, c):
            return m == 0 or m >= 0


        lSuccesori = []
        if nod.informatie[2] == 1:
            misMalCurent = nod.informatie[0]
            canMalCurent = nod.informatie[1]
            misMalOpus = Graf.N - nod.informatie[0]
            canMalOpus = Graf.N - nod.informatie[1]
        else:
            misMalOpus = nod.informatie[0]
            canMalOpus = nod.informatie[1]
            misMalCurent = Graf.N - nod.informatie[0]
            canMalCurent = Graf.N - nod.informatie[1]
        maxMisBarca = min(misMalCurent, Graf.M)
        for mb in range(maxMisBarca + 1):
            if mb == 0:
                minCanBarca = 1
                maxCanBarca = min(canMalCurent, Graf.M)
            else:
                minCanBarca = 0
                maxCanBarca = min(canMalCurent, Graf.M - mb, mb)
            for cb in range(minCanBarca, maxCanBarca + 1):
                misMalCurentNou = misMalCurent - mb
                canMalCurentNou = canMalCurent - cb
                misMalOpusNou = misMalOpus + mb
                canMalOpusNou = canMalOpus + cb
                if not testConditie(misMalCurentNou, canMalCurentNou):
                    continue
                if not testConditie(misMalOpusNou, canMalOpusNou):
                    continue
                if nod.informatie[2] == 1:
                    infoSuccesor = (misMalCurentNou, canMalCurentNou, 0)
                else:
                    infoSuccesor = (misMalOpus, canMalOpusNou, 1)

                if not nod.inDrum(infoSuccesor):
                    lSuccesori.append(NodArbore(infoSuccesor, nod))
        return lSuccesori
    
def breadthFirst(gr, nsol = 2):
    coada = [NodArbore(gr.start)]
    while coada:
        nodCurent = coada.pop(0)
        if gr.scop(nodCurent.informatie):
            print(repr(nodCurent))
            nsol -= 1
            if nsol == 0:
                return
        coada += gr.succesori(nodCurent)

f = open("input.txt", "r")
[Graf.N, Graf.M] = f.readline().strip().split()
Graf.N = int(Graf.N)
Graf.M = int(Graf.M)

#(numar_misionari_mal_initial, numar_canibali_mal_initial, mal_curent
#mal initial = 1, final = 0
start = (Graf.N, Graf.N, 1)
scopuri = [(0, 0, 0)]

gr = Graf(start,scopuri)
breadthFirst(gr, 10)




