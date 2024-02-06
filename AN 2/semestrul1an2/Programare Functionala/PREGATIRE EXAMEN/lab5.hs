import Distribution.Simple.PackageIndex (SearchResult(None))
--suma patrate elem impare 

addifImpar a e
    | a `mod` 2 == 1 = a + e
    | otherwise = e

sumaElemImpare :: [Int] -> Int
sumaElemImpare lista = foldr (addifImpar) 0 lista

toateTrue :: [Bool] -> Bool
toateTrue lista = foldr (\a e -> a && e) True lista


allVerifies :: (Int -> Bool) -> [Int] -> Bool
allVerifies f lista = toateTrue (map f lista)

unaTrue :: [Bool] -> Bool
unaTrue lista = foldr (\a e -> a || e) False lista

anyVerifies :: (Int -> Bool) -> [Int] -> Bool
anyVerifies f lista = unaTrue (map f lista)

mapFoldr :: (a -> b) -> [a] -> [b]
mapFoldr f lista = foldr (\a e -> (f a) : e) [] lista


putIfTrue :: (a -> Bool) -> a -> [a] -> [a]
putIfTrue f a list
    | (f a) == True = a : list
    | otherwise = list

filterFoldr :: (a -> Bool) -> [a] -> [a]
filterFoldr f lista = foldr (\a e -> (putIfTrue f a e)) [] lista

listToInt :: [Integer]-> Integer
listToInt lista = foldl (\e a -> e * 10 + a) 0 lista

rmFromString :: Char -> [Char] -> [Char]
rmFromString ch list = [a | a <- list, a /= ch]

returnIfDiff :: Char -> Char -> Char
returnIfDiff ch1 ch2
    | ch1 /= ch2 = ch1
    | otherwise = '.'


rmChar :: Char -> String -> String
rmChar ch lista = foldr (\a e -> (returnIfDiff a ch):e) "" lista


myReverse :: [Int] -> [Int]
myReverse lista = foldl (\e a -> a : e) [] lista

myElem :: Int -> [Int] -> Bool
myElem el lista
    | length [x | x <- lista, x /= el] == 0 = False
    | otherwise = True

myUnzip :: [(a, b)] -> ([a], [b])
myUnzip lista = foldr (\a e -> (fst e ++ [fst a], snd e ++ [snd a])) ([], []) lista

putIfNotThere :: Int -> [Int] -> [Int]
putIfNotThere a lista
    | not(a `elem` lista) = a : lista 
    | otherwise = lista

union :: [Int] -> [Int] -> [Int]
union list1 list2 = foldr (\a e -> putIfNotThere a e) list1 list2
--pun list2 la list1


putIfThere :: Int -> [Int] -> [Int] -> [Int]
putIfThere a lista1 lista2
    | a `elem` lista1 = a : lista2
    | otherwise = lista2

intersect :: [Int] -> [Int] -> [Int]
intersect list1 list2 = foldl (\e a -> (putIfThere a list2 e)) [] list1