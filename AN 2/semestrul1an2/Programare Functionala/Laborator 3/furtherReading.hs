head' :: [a] -> a
head' [] = error "Can't find Head"
head' (x:xs) = x

tell :: (Show a) => [a] -> String
tell [] = "Lista este vida"
tell (x:[]) = "Lista are un element: "  ++ (show x)
tell (x:y:[]) = "Lista are doua elemente: " ++ (show x) ++ " si " ++ (show y)
tell (x:y:xs) = "Lista are mai multe elemente, dar primele doua sunt: " ++ show x ++ " si " ++ show y

length' :: (Num b) => [a] -> b
length' [] = 0
length' (x:xs) = 1 + length' xs

capital :: String -> String
capital "" = "Empty string!"
capital all@(x:xs) = "The first letter of " ++ all ++ " is " ++ [x]

bmi :: (RealFloat a) => a -> String
bmi myBmi 
    | myBmi < 10.32 = "Slab"
    | myBmi < 30 = "Mediu"
    | otherwise = "wtf"

bmiTell :: (RealFloat a) => a -> a -> String
bmiTell w h 
    | bmi <= 18.5 = "Under"
    | bmi <= 25.0 = "Medium"
    | bmi <= 30 = "Fat"
    | otherwise = "Nononon"
    where bmi = w/h ^ 2

initials :: String -> String -> String
initials firstName lastName = [f] ++ ". "  ++ [l] ++"." 
    where (f:_) = firstName; (l:_) = lastName

calcBmis :: (RealFloat a) => [(a, a)] -> [a]
calcBmis x = [bmi w h | (w, h) <- x]
            where bmi weight height = weight / height^2

