import Data.Ratio (numerator)
import GHC.Base (RuntimeRep(AddrRep))
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
data List a = Nil
            | Cons a (List a)
        deriving (Eq, Show)

instance Functor List where
    fmap f Nil = Nil
    fmap f (Cons a list) = Cons (f a) (fmap f list)

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
noEmpty str
    | str == "" = Nothing
    | otherwise = Just str

noNegative :: Int -> Maybe Int
noNegative n
    | n < 0 = Nothing
    | otherwise = Just n

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
cowFromString' nume varsta greutate = fmap Cow (noEmpty nume) <*> (noNegative varsta) <*> (noNegative greutate)

test24 = cowFromString "Milka" 5 100 == Just (Cow {name = "Milka", age = 5, weight = 100})

newtype Name = Name String deriving (Eq, Show)
newtype Address = Address String deriving (Eq, Show)

data Person = Person Name Address
    deriving (Eq, Show)

validateLength :: Int -> String -> Maybe String
validateLength nr str
    | length str < nr = Just str
    | otherwise = Nothing

test31 = validateLength 5 "abc" == Just "abc"

mkName :: String -> Maybe Name
mkName str
    | length str <= 25 = Just (Name str)
    | otherwise = Nothing

mkAddress :: String -> Maybe Address
mkAddress str
    | length str <= 100 = Just (Address str)
    | otherwise = Nothing

test32 = mkName "Gigel" ==  Just (Name "Gigel")
test33 = mkAddress "Str Academiei" ==  Just (Address "Str Academiei")

mkPerson :: String -> String -> Maybe Person
mkPerson nume adresa = do
                new_nume <- mkName nume 
                new_adresa <- mkAddress adresa 
                return (Person new_nume new_adresa)

test34 = mkPerson "Gigel" "Str Academiei" == Just (Person (Name "Gigel") (Address "Str Academiei"))

mkPerson' :: String -> String -> Maybe Person
mkPerson' nume adresa = fmap Person (mkName nume) <*> (mkAddress adresa)

test35 = mkPerson' "Gigel" "Str Academiei" == Just (Person (Name "Gigel") (Address "Str Academiei"))