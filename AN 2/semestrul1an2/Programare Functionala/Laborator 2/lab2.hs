poly :: Integer -> Integer -> Integer -> Integer -> Integer
poly a b c x = a*x*x + b*x + c

eeny :: Integer -> [Char]
eeny x = if even x then "eeny"
        else "meeny"

fizzbuzz :: Integer -> [Char]
fizzbuzz x = if x `mod` 3 == 0 && x `mod` 5 == 0 then "FizzBuzz"
            else if x `mod` 3 == 0 then "Fizz"
            else if x `mod` 5 == 0 then "Buzz"
            else ""

fizzbuzz' :: Integer -> [Char]
fizzbuzz' x | x `mod` 3 == 0 && x `mod` 5 == 0 = "FizBuzz"
            | x `mod` 3 == 0 = "Fizz"
            | x `mod` 5 == 0 = "Buzz"
            | otherwise =  ""

tribonacci :: Integer -> Integer 
tribonacci n   | n == 1 = 1
                | n == 2 = 2
                | n == 3 = 3
                | otherwise = tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3)

coefBinomiali :: Integer -> Integer -> Integer
coefBinomiali x y   | y == 0 = 1
                    | x == 0 = 0
                    | otherwise = coefBinomiali (x - 1) y + coefBinomiali (x - 1) (y - 1)

verifL :: [Int] -> Bool
verifL xs = if even (length xs) then True
            else False

takefinal :: [Int] -> Int -> [Int]
takefinal xs n = drop (length(xs) - n) xs

remove :: [Int] -> Int -> [Int]
remove xs n = take (n - 1) xs ++ drop n xs

myreplicate :: Int -> Int -> [Int]
myreplicate 0 x = []
myreplicate n x = x : myreplicate (n - 1) x

sumImp :: [Int] -> Int
sumImp [] = 0
sumImp (x:xs) = if odd x then x + sumImp xs
                else sumImp xs

totalLen :: [String] -> Int
totalLen [] = 0
totalLen (x:xs) = if head(x) == 'A' then length(x) + totalLen(xs)
                else totalLen(xs)