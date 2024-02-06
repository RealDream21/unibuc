{-
[x^2 |x <- [1..10], x `rem` 3 == 2]
[(x,y) | x <- [1..5], y <- [x..(x+2)]]
[(x,y) | x <- [1..3], let k = x^2, y <- [1..k]]
[x | x <- "Facultatea de Matematica si Informatica", elem x ['A'..'Z']]
[[x..y] | x <- [1..5], y <- [1..5], x < y]
-}
factori :: Int -> [Int]
factori a = [x | x <- [1..a], a `mod` x == 0]

prim :: Int -> Bool
prim a
    | length (factori a) == 2 = True
    | otherwise = False

numerePrime :: Int -> [Int]
numerePrime a = [x | x <- [1..a], prim x]

myzip3 :: [Int] -> [Int] -> [Int] -> [(Int, Int, Int)]
myzip3 [] _ _ = []
myzip3 _ [] _ = []
myzip3 _ _ [] = []
myzip3 (a:as) (b:bs) (c:cs) = [(a, b, c)] ++ myzip3 as bs cs

firstEl :: [(a,b)] -> [a]
firstEl lista = map (\t -> fst t) lista

sumList :: [[Int]] -> [Int]
sumList lista = map (\t -> sum t) lista


app x
    | x `mod` 2 == 1 = x * 2
    | otherwise = x `div` 2

prel2 :: [Int] -> [Int]
prel2 lista = map (\t -> app t) lista

auCaract :: Char -> [String] -> [String]
auCaract ch lista = filter (\t -> ch `elem` t) lista


patrateNrImpare :: [Int] -> [Int]
patrateNrImpare lista = map (\t -> t ^ 2) (filter (\t -> t `mod` 2 == 1) lista)

aux :: [Int] -> [(Int, Int)]
aux lista = filter (\t -> (fst t) `mod` 2 == 1) (zip [0..] lista)


patratePozImpare :: [Int] -> [Int]
patratePozImpare lista = map (\t -> (snd t) * (snd t)) (aux lista)


elimCons :: [Char] -> [Char]
elimCons lista = [x | x <- lista, x `elem` "aeiouAEIOU"]

numaiVocale :: [String] -> [String]
numaiVocale lista = map (elimCons) lista

mymap :: (a -> b) -> [a] -> [b]
mymap f [] = []
mymap f (x:xs) = (f x) : (mymap f xs)

myfilter :: (a -> Bool) -> [a] -> [a]
myfilter f [] = []
myfilter f (x:xs)
    | (f x) == True = x : (myfilter f xs)
    | otherwise = myfilter f xs