import Data.String (IsString)
import Distribution.Compat.Lens (_1)
--ex1 suma patratelor elementelor impare
cerinta_1 :: [Int] -> Int
cerinta_1 xs = foldl (\a b -> b * b + a) 0 (filter (\t -> t `mod` 2 == 1) xs) -- a este elementul neutru

--ex2
cerinta_2 :: [Bool] -> Bool
cerinta_2 xs = foldr (\a b -> a && b) True xs

--ex3
allVerifies :: (Int -> Bool) -> [Int] -> Bool
allVerifies prop xs = cerinta_2 (map prop xs)

--ex4
anyVerifiesFold :: [Bool] -> Bool
anyVerifiesFold xs = foldl (\a b -> a || b) False xs

anyVerifies :: (Int -> Bool) -> [Int] -> Bool
anyVerifies prop xs = anyVerifiesFold (map prop xs)

--ex5
mapFoldr :: (a -> b) -> [a] -> [b]
mapFoldr f xs = foldr (\a e -> (f a): e) [] xs

condFoldr :: (a -> Bool) -> a -> [a] -> [a]
condFoldr f x xs
    | f x == True = x:xs
    | otherwise = xs
filterFoldr :: (a -> Bool) -> [a] -> [a]
filterFoldr f xs = foldr (\a e -> condFoldr f a e) [] xs

--ex6
listToInt :: [Integer]-> Integer
listToInt xs = foldl (\e a -> e * 10 + a) 0 xs

--ex7
--a
rmChar :: Char -> String -> String
rmChar c str = filter (\t -> t /= c) str

--b
rmCharsRec :: String -> String -> String
rmCharsRec [] str2 = str2
rmCharsRec str1 [] = []
rmCharsRec (s:str1) str2 = rmCharsRec str1 (rmChar s str2)

--c
rmCharsFold :: String -> String -> String
rmCharsFold str1 str2 = foldr (\a e -> (rmChar a e)) str2 str1
    
myUnzip :: [(a, b)] -> ([a], [b])
myUnzip = undefined
