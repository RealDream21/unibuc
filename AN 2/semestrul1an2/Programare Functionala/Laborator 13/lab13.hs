
{- Monada Maybe este definita in GHC.Base 

instance Monad Maybe where
  return = Just
  Just va  >>= k   = k va
  Nothing >>= _   = Nothing


instance Applicative Maybe where
  pure = return
  mf <*> ma = do
    f <- mf
    va <- ma
    return (f va)       

instance Functor Maybe where              
  fmap f ma = pure f <*> ma   
-}

{-da1 x y = do
  result1 <- safeDivide x y
  result2 <- addOne result1
  return result-}




pos :: Int -> Bool
pos  x = if (x>=0) then True else False

fct :: Maybe Int ->  Maybe Bool
fct  mx = do
  x <- mx
  return (pos x)

addM :: Maybe Int -> Maybe Int -> Maybe Int
addM Nothing (Just a) = Nothing
addM (Just a) Nothing = Nothing
addM (Just x) (Just y) = Just (x + y)

addM' :: Maybe Int -> Maybe Int -> Maybe Int
addM' mx my = do
  x <- mx
  y <- my
  return (x + y)

cartesian_product xs ys = xs >>= ( \x -> (ys >>= \y-> return (x,y)))
cartesian_product' :: Monad m => m a -> m b -> m (a, b)
cartesian_product' xs ys = do
    x <- xs
    y <- ys
    return (x, y)

prod f xs ys = [f x y | x <- xs, y<-ys]
prod' f xs ys = do
  x <- xs
  y <- ys
  return f x y

myGetLine :: IO String
myGetLine = getChar >>= \x ->
      if x == '\n' then
          return []
      else
          myGetLine >>= \xs -> return (x:xs)

myGetLine' :: IO String
myGetLine' = do
  x <- getChar
  if x == '\n' then
    return []
  else do
    xs <- myGetLine'
    return (x:xs)

prelNo noin =  sqrt noin

ioNumber = do
     noin  <- readLn :: IO Float
     putStrLn $ "Intrare\n" ++ (show noin)
     let  noout = prelNo noin
     putStrLn $ "Iesire"
     print noout

ioNumber' = (readLn :: IO Float) >>= 
            \noin -> (putStrLn ("Intrare\n" ++ (show noin))
            >> let noout = prelNo noin in putStrLn "Iesire" >> print noout)


data Person = Person { name :: String, age :: Int }

showPersonN :: Person -> String
showPersonN (Person name age) = "NAME: " ++ name
showPersonA :: Person -> String
showPersonA (Person name age) = "AGE: " ++ show age

{-
showPersonN $ Person "ada" 20
"NAME: ada"
showPersonA $ Person "ada" 20
"AGE: 20"
-}

showPerson :: Person -> String
showPerson (Person name age) = "(" ++ (showPersonN (Person name age)) ++ ", " ++ (showPersonA (Person name age)) ++ ")"

{-
showPerson $ Person "ada" 20
"(NAME: ada, AGE: 20)"
-}

newtype Reader env a = Reader { runReader :: env -> a }


instance Monad (Reader env) where
  return x = Reader (\_ -> x)
  ma >>= k = Reader f
    where f env = let a = runReader ma env
                  in  runReader (k a) env



instance Applicative (Reader env) where
  pure = return
  mf <*> ma = do
    f <- mf
    a <- ma
    return (f a)       

instance Functor (Reader env) where              
  fmap f ma = pure f <*> ma    

mshowPersonN ::  Reader Person String
mshowPersonN = Reader (\p -> "NAME: " ++ name p)
mshowPersonA ::  Reader Person String
mshowPersonA = Reader(\p -> "AGE: " ++ show(age p))
mshowPerson ::  Reader Person String
mshowPerson = do
  n <- mshowPersonN
  a <- mshowPersonA
  return $ "(" ++ n ++ ", " ++ a ++ ")"
{-
runReader mshowPersonN  $ Person "ada" 20
"NAME:ada"
runReader mshowPersonA  $ Person "ada" 20
"AGE:20"
runReader mshowPerson  $ Person "ada" 20
"(NAME:ada,AGE:20)"
-}



--ex de examen
--ex1 nu e bine
ex1 :: [Int] -> Int
ex1 [] = 0
ex1 (a:[]) = 0
ex1 (a:b:[])
  | (a `mod` 3 == 0 && b `mod` 3 == 0) = a - b
  | otherwise = (a * b)
ex1 (a:b:xs)
  | (a `mod` 3 == 0 && b `mod` 3 == 0) = a - b + ex1 xs
  | otherwise = (a * b) + ex1 xs

nrVocale :: String -> Int
nrVocale [] = 0
nrVocale (c:str)
  | (c `elem` "aeiou") = 1 + nrVocale str
  | otherwise = nrVocale str

nrConsoane :: String -> Int
nrConsoane [] = 0
nrConsoane (c:str)
  | (c `notElem` "aeiou") = 1 + nrConsoane str
  | otherwise = nrConsoane str

vocaleEgalConsoane :: String -> Bool
vocaleEgalConsoane str
  | ((nrVocale str == nrConsoane str) && ((nrVocale str + nrConsoane str) == (length str))) = True
  | otherwise = False


ex2 :: [String] -> Int -> [Bool]
ex2 lista nr = map (\t -> vocaleEgalConsoane t) (filter (\t -> length t >= nr) lista)