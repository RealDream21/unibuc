data Fruct
  = Mar String Bool
  | Portocala String Int

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
ePortocalaDeSicilia (Mar _ _) = False
ePortocalaDeSicilia (Portocala soi felii)
    | soi == "Tarocco" = True
    | soi == "Moro" = True
    | soi == "Sanguinello" = True
    | otherwise = False

test_ePortocalaDeSicilia1 =
    ePortocalaDeSicilia (Portocala "Moro" 12) == True
test_ePortocalaDeSicilia2 =
    ePortocalaDeSicilia (Mar "Ionatan" True) == False

nrFeliiPortocala :: Fruct -> Int
nrFeliiPortocala (Mar _ _ ) = 0
nrFeliiPortocala (Portocala soi felii) = felii

nrFeliiSicilia :: [Fruct] -> Int
nrFeliiSicilia [] = 0
nrFeliiSicilia (x:xs)
    | ePortocalaDeSicilia x = nrFeliiPortocala x + nrFeliiSicilia xs 
    | otherwise = nrFeliiSicilia xs

test_nrFeliiSicilia = nrFeliiSicilia listaFructe == 52


nrViermiMar :: Fruct -> Int
nrViermiMar (Portocala _ _) = 0
nrViermiMar (Mar _ are)
    | are == True = 1
    | otherwise = 0

nrMereViermi :: [Fruct] -> Int
nrMereViermi lista = foldr (\a e -> nrViermiMar a + e) 0 lista 

test_nrMereViermi = nrMereViermi listaFructe == 2

type NumeA = String
type Rasa = String
data Animal = Pisica NumeA | Caine NumeA Rasa
    deriving Show

vorbeste :: Animal -> String
vorbeste (Pisica _) = "Meow!"
vorbeste (Caine _ _ ) = "Woof!"

rasa :: Animal -> Maybe String
rasa (Pisica _) = Nothing
rasa (Caine _ rasa) = Just rasa

data Linie = L [Int]
   deriving Show
data Matrice = M [Linie]
   deriving Show

verificaLinie :: Linie -> Int -> Bool
verificaLinie (L xs) nr
    | sum xs == nr = True
    | otherwise = False

verifica :: Matrice -> Int -> Bool
verifica (M []) a = True
verifica (M (x:xs)) nr = (verificaLinie x nr) && verifica (M xs) nr

test_verif1 = verifica (M[L[1,2,3], L[4,5], L[2,3,6,8], L[8,5,3]]) 10 == False
test_verif2 = verifica (M[L[2,20,3], L[4,21], L[2,3,6,8,6], L[8,5,3,9]]) 25 == True


verifLinN :: Linie -> Int -> Bool
verifLinN (L xs) n
    | (length xs < n) = True
    | (length xs >= n) && (length [x| x <- xs, x >= 0] == length xs) = True
    | otherwise = False

doarPozN :: Matrice -> Int -> Bool
doarPozN (M []) a = True
doarPozN (M (x:xs)) n = (verifLinN x n) && doarPozN (M xs) n

testPoz1 = doarPozN (M [L[1,2,3], L[4,5], L[2,3,6,8], L[8,5,3]]) 3 == True

testPoz2 = doarPozN (M [L[1,2,-3], L[4,5], L[2,3,6,8], L[8,5,3]]) 3 == False



catePeLinie :: Linie -> Int
catePeLinie (L xs) = length xs

allSame :: [Int] -> Bool
allSame [] = True
allSame (x:[]) = True
allSame (x:xs)
    | x == head xs = True && allSame xs
    | otherwise = False

corect :: Matrice -> Bool
corect (M xs) = allSame [catePeLinie t | t <- xs]


testcorect1 = corect (M[L[1,2,3], L[4,5], L[2,3,6,8], L[8,5,3]]) == False
testcorect2 = corect (M[L[1,2,3], L[4,5,8], L[3,6,8], L[8,5,3]]) == True
