import Data.Char (isUpper, isLower)
removeCaps :: [Char] -> [Char]

removeCaps [] = []
removeCaps(x:xs) = if isLower x then x : removeCaps xs
                    else removeCaps xs

removeCaps' :: [Char] -> [Char]
removeCaps' [] = []
removeCaps' xs = [x | x <- xs, x `elem` ['a'..'z']]
