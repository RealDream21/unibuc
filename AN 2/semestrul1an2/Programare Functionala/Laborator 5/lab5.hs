sumaPatrate :: [Int] -> Int
sumaPatrate xs = foldl (+) 0 (map (^2) (filter odd xs))

allTrue :: [Bool] -> Bool
allTrue xs = foldl (&&) True xs

anyTrue :: [Bool] -> Bool
anyTrue xs = foldl (||) False xs

allVerifies :: (Int -> Bool) -> [Int] -> Bool
allVerifies f xs = allTrue (map f xs)

anyVerifies :: (Int -> Bool) -> [Int] -> Bool
anyVerifies f xs = anyTrue (map f xs)

mapFoldr :: (a -> b) -> [a] -> [b]
mapFoldr f xs = foldr(\x end -> (f x):end) [] xs

filterFoldr :: (a -> Bool) -> [a] -> [a]
filterFoldr f xs = foldr(\x end -> if f x == True then x : end else end) [] xs

listToInt :: [Integer]-> Integer
listToInt xs = foldl (\acc x -> x * 10 + acc) 0 xs

rmChar :: Char -> String -> String
rmChar c str = filter (\t -> if t == c then False else True) str

rmCharsRec :: String -> String -> String
rmCharsRec [] s2 = s2
rmCharsRec (s:s1) s2 = rmCharsRec (s1) (rmChar s s2) 

rmCharsFold :: String -> String -> String
rmCharsFold s1 s2 = foldr rmChar s2 s1
    
myReverse :: [Int] -> [Int]
myReverse xs = foldr f e xs
            where
                f x r = r ++ [x]
                e = []

myUnzip :: [(a, b)] -> ([a], [b])
myUnzip xs = ([fst x| x <- xs], [snd x | x <- xs])

myUnzip' :: [(a, b)] -> ([a], [b])
myUnzip' xs = foldr(\(a, b) (acc1, acc2) -> (a:acc1, b:acc2)) ([], []) xs

appendIfNotThere :: [Int] -> Int -> [Int]
appendIfNotThere [] a = [a]
appendIfNotThere xs y = if y `elem` xs then xs
                        else y : xs

union :: [Int] -> [Int] -> [Int]
union xs ys = foldl appendIfNotThere xs ys


appendIfThere :: [Int] -> Int -> [Int]
appendIfThere [] a = [a]
appendIfThere xs y = if y `elem` xs then xs
                    else y : xs

intersect :: [Int] -> [Int] -> [Int]
intersect xs ys = foldl appendIfThere xs ys