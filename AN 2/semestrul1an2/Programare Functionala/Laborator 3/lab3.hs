import Data.Char
import Data.List

cateVocale :: String -> Int
cateVocale [] = 0
cateVocale (x:xs) = if x `elem` "aeiouAEIOU" then 1 + cateVocale xs
                    else cateVocale xs

nrVocale :: [String] -> Int
nrVocale [] = 0
nrVocale (x:xs) = if x:xs == reverse (x:xs) then cateVocale x + nrVocale xs
                    else nrVocale xs

adaugaPar :: Int -> [Int] -> [Int]
adaugaPar a [] = []
adaugaPar a (x:xs) = if even x then (x:a:[]) ++ adaugaPar a xs
                    else (x:[]) ++ adaugaPar a xs

divizori :: Int -> [Int]
divizori x = [i | i <- [1..x], x `mod`i == 0]

listadiv :: [Int] -> [[Int]]
listadiv [] = []
listadiv (x:xs) = (divizori x) : (listadiv xs)

inIntervalRec :: Int -> Int -> [Int] -> [Int]
inIntervalRec x y [] = []
inIntervalRec a b (x:xs) = if x >= a && x <= b then x : inIntervalRec a b xs
                        else xs

inIntervalComp :: Int -> Int -> [Int] -> [Int] 
inIntervalComp x y xs = [i| i <- xs, i >= x, i <= y]

pozitiveRec :: [Int] -> Int
pozitiveRec [] = 0
pozitiveRec (x:xs) = if x >= 0 then 1 + pozitiveRec xs
                    else pozitiveRec xs

pozitiveComp :: [Int] -> Int
pozitiveComp xs = length [x| x <- xs, x >= 0]

pozitiiImpareComp :: [Int] -> [Int]
pozitiiImpareComp xs = [x| (x, y) <- zip [0..] xs, odd y]

pozitiiImpareRecAux :: Int -> [Int] -> [Int]
pozitiiImpareRecAux a [] = []
pozitiiImpareRecAux a (x:xs) = if odd x then a: pozitiiImpareRecAux (a + 1) xs
                            else pozitiiImpareRecAux (a + 1) xs
    
pozitiiImpareRec :: [Int] -> [Int] 
pozitiiImpareRec xs = pozitiiImpareRecAux 0 xs

multDigitsRec :: String -> Int
multDigitsRec [] = 1
multDigitsRec (x:xs) = if isDigit x then digitToInt(x) * (multDigitsRec xs)
                    else multDigitsRec xs

multList :: [Int] -> Int
multList [] = 1
multList (x:xs) = x * multList xs

multDigitsComp :: String -> Int
multDigitsComp xs = multList [digitToInt(x) | x <- xs, x `elem` ['1'..'9']]

permutari :: [Int] -> [[Int]]
permutari xs = permutations xs

aranjamenteK :: [Int] -> Int -> [[Int]]
aranjamenteK xs k = take k permuta