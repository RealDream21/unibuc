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
    
    def afisSolFisier(self, fisier): #nu inteleg de ce nu se printeaza in ordinea ok??????
        lista_drumuri = [drum.informatie for drum in self.drumRadacina()]
        canibaliTotali = lista_drumuri[0][0]
        misionariTotali = lista_drumuri[0][1]
        nrCanibaliInsula = canibaliTotali
        nrMisionariInsula = misionariTotali
        for i, actiune in enumerate(lista_drumuri):
            if i == len(lista_drumuri) - 1:
                fisier.write(f"(Stanga) 0 canibali 0 misionari ..... (Dreapta:<barca>) {canibaliTotali} canibali {misionariTotali} misionari\n")
                break
            if actiune[2] == 1:
                fisier.write(f"(Stanga:<barca>) {nrCanibaliInsula} canibali {nrMisionariInsula} misionari ..... (Dreapta) {canibaliTotali - nrCanibaliInsula} canibali {misionariTotali - nrMisionariInsula} misionari\n")
                fisier.write("\n")
                fisier.write(f">>> Barca s-a deplasat de la malul stang la malul drept cu {actiune[0] - lista_drumuri[i + 1][0]} canibali si {actiune[1] - lista_drumuri[i + 1][1]} misionari\n")
                nrCanibaliInsula -= actiune[0] - lista_drumuri[i + 1][0]
                nrMisionariInsula -= actiune[1] - lista_drumuri[i + 1][1]
            else:
                fisier.write(f"(Stanga) {nrCanibaliInsula} canibali {nrMisionariInsula} misionari ..... (Dreapta:<barca>) {canibaliTotali - nrCanibaliInsula} canibali {misionariTotali - nrMisionariInsula} misionari\n")
                fisier.write("\n")
                fisier.write(f">>> Barca s-a deplasat de la malul drept la malul stang cu {lista_drumuri[i + 1][0] - actiune[0]} canibali si {lista_drumuri[i + 1][1] - actiune[1]} misionari\n")
                nrCanibaliInsula += lista_drumuri[i + 1][0] - actiune[0]
                nrMisionariInsula += lista_drumuri[i + 1][1] - actiune[1]
        fisier.write("\n\n\n\n\n\n\n\n\n\n")
        return

    
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
        def testConditie(m,c):
            return m==0 or m>=c

        lSuccesori=[]
        if nod.informatie[2]==1:
            misMalCurent=nod.informatie[0]
            canMalCurent=nod.informatie[1]
            misMalOpus=Graf.N-nod.informatie[0]
            canMalOpus=Graf.N-nod.informatie[1]
        else:
            misMalOpus=nod.informatie[0]
            canMalOpus=nod.informatie[1]
            misMalCurent=Graf.N-nod.informatie[0]
            canMalCurent=Graf.N-nod.informatie[1]
        maxMisBarca=min(misMalCurent, Graf.M)
        for mb in range(maxMisBarca+1):
            if mb==0:
                minCanBarca=1
                maxCanBarca=min(canMalCurent, Graf.M)
            else:
                minCanBarca=0
                maxCanBarca=min(canMalCurent, Graf.M-mb, mb )
            for cb in range(minCanBarca,maxCanBarca + 1):
                misMalCurentNou=misMalCurent-mb
                canMalCurentNou=canMalCurent-cb
                misMalOpusNou=misMalOpus+mb
                canMalOpusNou=canMalOpus+cb
                if not testConditie(misMalCurentNou,canMalCurentNou):
                    continue
                if not testConditie(misMalOpusNou,canMalOpusNou):
                    continue
                if nod.informatie[2]==1:
                    infoSuccesor=(misMalCurentNou,canMalCurentNou,0)
                else:
                    infoSuccesor = (misMalOpusNou, canMalOpusNou, 1)
                    
                if  not nod.inDrum(infoSuccesor):
                    lSuccesori.append(NodArbore(infoSuccesor,nod))
        return lSuccesori
    
def breadthFirst(gr, nsol = 2):
    file = open("output.txt", "w")
    coada = [NodArbore(gr.start)]
    while coada:
        nodCurent = coada.pop(0)
        if gr.scop(nodCurent.informatie):
            #print(repr(nodCurent))
            nodCurent.afisSolFisier(file)
            nsol -= 1
            if nsol == 0:
                return
        coada += gr.succesori(nodCurent)
    file.close()


f = open("input.txt", "r")
[Graf.Nm, Graf.Nc, Graf.M] = f.readline().strip().split()
Graf.Nm = int(Graf.Nc)
Graf.Nc = int(Graf.Nm)
Graf.M = int(Graf.M)

#(numar_misionari_mal_initial, numar_canibali_mal_initial, mal_curent
#mal initial = 1, final = 0
start = (Graf.N, 0, 1)
scopuri = [(0, Graf.N, 1), (0, Graf.N, 0)]

gr = Graf(start,scopuri)
breadthFirst(gr, 10)
