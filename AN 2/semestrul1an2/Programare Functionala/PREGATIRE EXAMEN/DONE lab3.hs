import Data.Char (digitToInt)
--nr vocale din sirurile palindrom
--vreau cu fold + filter
isPalindrome :: String -> Bool
isPalindrome a
    | a == reverse a = True
    | otherwise = False

takeVocale :: [Char] -> [Char]
takeVocale [] = []
takeVocale (x:xs)
    | x `elem` "aeiou" = x : takeVocale xs
    | otherwise = takeVocale xs

nrVocale :: [String] -> Int
nrVocale a = foldl (\e t -> e + length (takeVocale t)) 0 (filter isPalindrome a)
-- nrVocale ["sos", "civic", "palton", "desen", "aerisirea"] == 9

-- f 3 [1,2,3,4,5,6] = [1,2,3,3,4,3,5,6,3]

f :: Int -> [Int] -> [Int]
f a [] = []
f a (x:xs)
    | x `mod` 2 == 0 = [x] ++ [a] ++ (f a xs)
    | otherwise = x : (f a xs)

semiPareComp :: [Int] -> [Int]
semiPareComp l = [ x `div` 2 | x <- l, even x ]

-- divizori 4 == [1,2,4]
divizori a = [x | x <- [1..a], a `mod`x == 0]

listadiv :: [Int] -> [[Int]]
listadiv lista = [divizori x | x <- lista]
-- listadiv [1,4,6,8] == [[1],[1,2,4],[1,2,3,6],[1,2,4,8]]

inInterval :: Int -> Int -> [Int] -> [Int]
inInterval a b list = [x | x <- list, a <= x, x <= b]
-- inInterval 5 10 [1..15] == [5,6,7,8,9,10]
-- inInterval 5 10 [1,3,5,2,8,-1] == [5,8]

-- pozitive [0,1,-3,-2,8,-1,6] == 3
pozitive :: [Int] -> Int
pozitive list = length [x | x <- list, x > 0]

pozitiveRec :: [Int] -> Int
pozitiveRec [] = 0
pozitiveRec (x:xs)
    | x > 0 = 1 + pozitiveRec xs
    | otherwise = pozitiveRec xs

-- pozitiiImpare [0,1,-3,-2,8,-1,6,1] == [1,2,5,7]
pozitiiImpare :: (Integral a1, Num a2, Enum a2) => [a1] -> [a2]
pozitiiImpare list = [i | (x, i) <- (zip list [0..]), x `mod` 2 == 1]

-- multDigits "The time is 4:25" == 40

-- multDigits "No digits here!" == 1

multDigitsRec :: [Char] -> Int
multDigitsRec [] = 1
multDigitsRec (x:xs)
    | x `elem` "123456789" = (digitToInt x) * multDigitsRec xs 
    | otherwise = multDigitsRec xs

multDigits str = product [digitToInt x | x <- str, x `elem` "123456789"]