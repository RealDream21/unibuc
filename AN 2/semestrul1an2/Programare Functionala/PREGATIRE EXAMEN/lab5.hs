--ex1
cerinta_1 :: [Int] -> [Int]
cerinta_1 xs = foldr (\q u -> q * 2 + u) 0 (filter (\t -> t `mod` 2 == 1) xs)




allVerifies :: (Int -> Bool) -> [Int] -> Bool
allVerifies = undefined

anyVerifies :: (Int -> Bool) -> [Int] -> Bool
anyVerifies = undefined

listToInt :: [Integer]-> Integer
listToInt = undefined

rmChar :: Char -> String -> String
rmChar = undefined

rmCharsRec :: String -> String -> String
rmCharsRec = undefined

rmCharsFold :: String -> String -> String
rmCharsFold = undefined
    
myUnzip :: [(a, b)] -> ([a], [b])
myUnzip = undefined
