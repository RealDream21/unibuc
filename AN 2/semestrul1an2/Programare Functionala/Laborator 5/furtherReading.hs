--create map using fold
myMap :: (a -> b) -> [a] -> [b]
myMap f l = foldr (\t acc -> (f t) : acc) [] l

listToInt :: [Integer] -> Integer
listToInt xs = foldl (\acc t -> acc * 10 + t) 0 xs

myElem :: Int -> [Int] -> Bool
myElem el xs = foldr (\t acc -> acc || (t == el)) False xs