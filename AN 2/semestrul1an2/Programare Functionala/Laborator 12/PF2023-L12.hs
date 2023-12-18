{- 
class Functor f where 
     fmap :: (a -> b) -> f a -> f b 
class Functor f => Applicative f where
    pure :: a -> f a
    (<*>) :: f (a -> b) -> f a -> f b

Just length <*> Just "world"

Just (++" world") <*> Just "hello,"
pure (+) <*> Just 3 <*> Just 5
pure (+) <*> Just 3 <*> Nothing
(++) <$> ["ha","heh"] <*> ["?","!"]
-}
data List a = Nil | Cons a (List a)
        deriving (Eq, Show)

instance Functor List where
    fmap g Nil = Nil
    fmap g (Cons a list) = Cons (g a) (fmap g list)

instance Applicative List where
    pure a = Cons a Nil
    Nil <*> list = Nil
    Cons f list <*> list2 = lappend (fmap f list2) (list <*> list2)
                            where
                                lappend Nil list = list
                                lappend (Cons a list) list2 = Cons a (lappend list list2)

f = Cons (+1) (Cons (*2) Nil)
v = Cons 1 (Cons 2 Nil)
test1 = (f <*> v) == Cons 2 (Cons 3 (Cons 2 (Cons 4 Nil)))

data Cow = Cow {
        name :: String
        , age :: Int
        , weight :: Int
        } deriving (Eq, Show)

noEmpty :: String -> Maybe String
noEmpty "" = Nothing
noEmpty s = Just s 

noNegative :: Int -> Maybe Int
noNegative a = if a < 0 then Nothing
                else Just a

test21 = noEmpty "abc" == Just "abc"
test22 = noNegative (-5) == Nothing 
test23 = noNegative 5 == Just 5 

cowFromString :: String -> Int -> Int -> Maybe Cow
cowFromString nume varsta greutate = do
                                new_nume <- noEmpty nume
                                new_varsta <- noNegative varsta
                                new_greutate <- noNegative greutate
                                return (Cow new_nume new_varsta new_greutate)

cowFromString' :: String -> Int -> Int -> Maybe Cow
cowFromString' n a w = Cow <$> noEmpty n <*> noNegative a <*> noNegative w

--cowFromString'' :: String -> Int -> Int -> Maybe Cow
--cowFromString'' n a w = fmap Cow (noEmpty n) <*> fmap noNegative .....

test24 = cowFromString' "Milka" 5 100 == Just (Cow {name = "Milka", age = 5, weight = 100})

newtype Name = Name String deriving (Eq, Show)
newtype Address = Address String deriving (Eq, Show)

data Person = Person Name Address
    deriving (Eq, Show)

validateLength :: Int -> String -> Maybe String
validateLength n s = if length(s) < n then Just s
                    else Nothing

test31 = validateLength 5 "abc" == Just "abc"
mkName :: String -> Maybe Name
mkName a = case (validateLength 25 a) of 
            Nothing -> Nothing
            Just a -> Just (Name a)

mkAddress :: String -> Maybe Address
mkAddress a = case (validateLength 100 a) of 
                Nothing -> Nothing
                Just a -> Just(Address a)

test32 = mkName "Gigel" ==  Just (Name "Gigel")
test33 = mkAddress "Str Academiei" ==  Just (Address "Str Academiei")

mkPerson :: String -> String -> Maybe Person
mkPerson n a = case mkName n of 
            Nothing -> Nothing
            Just n -> case mkAddress a of
                        Nothing -> Nothing
                        Just a -> Just (Person n a) 

test34 = mkPerson "Gigel" "Str Academiei" == Just (Person (Name "Gigel") (Address "Str Academiei"))

mkName2 s = Name <$> validateLength 25 s
mkAddress2 s = Address <$> validateLength 100 s
mkPerson2 n a = Person <$> mkName2 n <*> mkAddress2 a