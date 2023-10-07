doubleMe :: Num a => a -> a
doubleMe x = x + x

doubleUs :: Num a => a -> a -> a
doubleUs x y = doubleMe x + doubleMe y

doubleSmallNumber :: (Ord a, Num a) => a -> a
doubleSmallNumber x = if(x < 100) 
                        then 2 * x
                    else x

doubleSmallNumber' :: (Ord a, Num a) => a -> a
doubleSmallNumber' x = (if(x < 100)
                        then 2 * x
                        else x)
                        + 1

boomBang :: Integral a => [a] -> [String]
boomBang xs = [if x < 10 then "BOOM!" else "BANG!" | x <- xs, odd x]

length' :: Num a => [t] -> a
length' xs = sum [1| _ <- xs]