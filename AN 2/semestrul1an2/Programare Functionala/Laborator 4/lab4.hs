{-
[x^2 |x <- [1..10], x `rem` 3 == 2] => [4, 25, 64]
rem = restul impartirii => 
[(x,y) | x <- [1..5], y <- [x..(x+2)]] => [(1,1), (1,2), (1,3), (2,2), .. , (5,7)]
[(x,y) | x <- [1..3], let k = x^2, y <- [1..k]] => [(1,1), (2,1), (2,2), (2,3), (2,4), ..]
[x | x <- "Facultatea de Matematica si Informatica", elem x ['A'..'Z']] => "FMI"
[[x..y] | x <- [1..5], y <- [1..5], x < y] => [[1, 2], [1,2], [1,3], ..]
-}
factori :: Int -> [Int]
factori x = [d | d <- [1..x], x `mod` d == 0]

prim :: Int -> Bool
prim x
    | length (factori x) == 2 = True
    | otherwise = False

numerePrime :: Int -> [Int]
numerePrime x = [t | t <- [1..x], prim t]

myZip3 :: [a] -> [b] -> [c] -> [(a, b, c)]
myZip3 e1 e2 e3 = [(a, b, c) | (a, (b,c)) <- zip e1(zip e2 e3)]

firstEl :: [(a, b)] -> [a]
firstEl x = map fst x

sumList :: [[Int]] -> [Int]
sumList x = map sum x

prel2 :: [Int] -> [Int] 
prel2 x = map (\t -> if t `mod` 2 == 0 then t `div` 2 else t * 2) x

contin :: Char -> [String] -> [String]
contin c lista = filter (elem c) lista

patrate :: [Int] -> [Int]
patrate x = map (\t -> t ^ 2) (filter odd x)

patratePozImpare :: [Int] -> [Int]
patratePozImpare x = map (\(t,a) -> t * t) (filter (\(t,a) -> odd a) (zip x [0..]))

numaiVocale :: [String] -> [String]
numaiVocale x = map (filter (`elem` "aeiouAEIOU")) x

myMap :: (a -> Bool) -> [a] -> [a]
myMap f [] = []
myMap f (a:xs) = if f a then a : myMap f xs
                    else myMap f xs

myFilter :: (a -> b) -> [a] -> [b]
myFilter f [] = []
myFilter f (a:xs) = f a : myFilter f xs