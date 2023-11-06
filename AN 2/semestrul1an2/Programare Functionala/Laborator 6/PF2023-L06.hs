data Fruct = Mar String Bool | Portocala String Int

ionatanFaraVierme = Mar "Ionatan" False
goldenCuVierme = Mar "Golden Delicious" True
portocalaSicilia10 = Portocala "Sanguinello" 10
listaFructe = [Mar "Ionatan" False,
                Portocala "Sanguinello" 10,
                Portocala "Valencia" 22,
                Mar "Golden Delicious" True,
                Portocala "Sanguinello" 15,
                Portocala "Moro" 12,
                Portocala "Tarocco" 3,
                Portocala "Moro" 12,
                Portocala "Valencia" 2,
                Mar "Golden Delicious" False,
                Mar "Golden" False,
                Mar "Golden" True]

ePortocalaDeSicilia :: Fruct -> Bool
ePortocalaDeSicilia (Portocala s _) = s `elem` ["Tarocco", "Moro", "Sanguinello"]
ePortocalaDeSicilia (Mar _ _) = False

test_ePortocalaDeSicilia1 =
    ePortocalaDeSicilia (Portocala "Moro" 12) == True
test_ePortocalaDeSicilia2 =
    ePortocalaDeSicilia (Mar "Ionatan" True) == False

lambdaAdd :: Fruct -> Int -> Int
lambdaAdd (Mar _ _) acc = acc
lambdaAdd (Portocala _ i) acc = acc + i

nrFeliiSicilia :: [Fruct] -> Int
nrFeliiSicilia cos = foldr (lambdaAdd) 0 cos

test_nrFeliiSicilia = nrFeliiSicilia listaFructe == 52

lambdaAddViermi :: Fruct -> Int -> Int
lambdaAddViermi (Mar _ areViermi) acc = if areViermi then acc + 1
                                        else acc
lambdaAddViermi (Portocala _ _) acc = acc
nrMereViermi :: [Fruct] -> Int
nrMereViermi cos = foldr (lambdaAddViermi) 0 cos

test_nrMereViermi = nrMereViermi listaFructe == 2

type NumeA = String
type Rasa = String
data Animal = Pisica NumeA | Caine NumeA Rasa
    deriving Show

vorbeste :: Animal -> String
vorbeste (Pisica _) = "Meow"
vorbeste (Caine _ _) = "Woof!"

rasa :: Animal -> Maybe String
rasa (Caine _ rasa) = Just rasa
rasa (Pisica _) = Nothing

data Linie = L [Int]
   deriving Show
data Matrice = M [Linie]
   deriving Show

verifica :: Matrice -> Int -> Bool
verifica (M(L matr)) n  = foldr (\linieMatr acc -> (foldr (\t acc -> (t == n) && acc ) True linieMatr) && acc) True matr


test_verif1 = verifica (M[L[1,2,3], L[4,5], L[2,3,6,8], L[8,5,3]]) 10 == False
test_verif2 = verifica (M[L[2,20,3], L[4,21], L[2,3,6,8,6], L[8,5,3,9]]) 25 == True
doarPozN :: Matrice -> Int -> Bool
doarPozN = undefined

testPoz1 = doarPozN (M [L[1,2,3], L[4,5], L[2,3,6,8], L[8,5,3]]) 3 == True

testPoz2 = doarPozN (M [L[1,2,-3], L[4,5], L[2,3,6,8], L[8,5,3]]) 3 == False
corect :: Matrice -> Bool
corect = undefined

testcorect1 = corect (M[L[1,2,3], L[4,5], L[2,3,6,8], L[8,5,3]]) == False
testcorect2 = corect (M[L[1,2,3], L[4,5,8], L[3,6,8], L[8,5,3]]) == True
