{-
[x^2 |x <- [1..10], x `rem` 3 == 2]
[(x,y) | x <- [1..5], y <- [x..(x+2)]]
[(x,y) | x <- [1..3], let k = x^2, y <- [1..k]]
[x | x <- "Facultatea de Matematica si Informatica", elem x ['A'..'Z']]
[[x..y] | x <- [1..5], y <- [1..5], x < y]
-}
factori :: Int -> [Int]
factori n = [x | x <- [1..n], n `mod` x == 0]

prim :: Int -> Bool
prim n
    | length (factori n) == 2 = True
    | otherwise = False

numerePrime :: Int -> [Int]
numerePrime n = [x | x <- [2..n], prim x]

myzip3 :: [Int] -> [Int] -> [Int] -> [(Int, Int, Int)]
myzip3 [] _ _ = []
myzip3 _ [] _ = []
myzip3 _ _ [] = []
myzip3 (a:as) (b:bs) (c:cs) = [(a, b, c)] ++ myzip3 as bs cs

--6
firstEl :: [(a, b)] -> [a]
firstEl [] = []
firstEl (x:xs) = (fst x): firstEl xs

firstEl' :: [(a, b)] -> [a]
firstEl' xs = map fst xs

--7
sumList :: [[Int]] -> [Int]
sumList [] = []
sumList (x:xs) = (sum x):sumList xs

sumList' :: [[Int]] -> [Int]
sumList' xs = map sum xs

--8
f x
    | x `mod` 2 == 0 = x `div` 2
    | otherwise = x * 2
prel2 :: [Int] -> [Int]
prel2 xs = map f xs

--9
functie_9 :: Char -> [String] -> [String]
functie_9 c lista = filter (\t -> c `elem` t) lista

--10
functie_10 :: [Int] -> [Int]
functie_10 xs = map (\t -> t ^ 2) (filter (\t -> t `mod` 2 == 1) xs)

--11
functie_11 :: [Int] -> [Int]
functie_11 xs = map fst (filter (\(a, b) -> b `mod` 2 == 0) (zip xs [1..]))

--12
g :: String -> String
g xs = myfilter (\t -> t `elem` "aeiou") xs

functie_12 :: [String] -> [String]
functie_12 lista = mymap g lista

--13
mymap :: (a -> b) -> [a] -> [b]
mymap f [] = []
mymap f (x:xs) = (f x): mymap f xs

myfilter :: (a -> Bool) -> [a] -> [a]
myfilter f [] = []
myfilter f (x:xs)
    | f x == True = x:myfilter f xs
    | otherwise = myfilter f xs