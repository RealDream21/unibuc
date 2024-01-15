data Point = Pt [Int]
            deriving Show

data Arb = Empty | Node Int Arb Arb
            deriving Show

class ToFromArb a where
    toArb :: a -> Arb
    fromArb :: Arb -> a

instance ToFromArb Point where
    toArb(Pt[]) = Empty
    toArb(Pt(x:xs)) = Node x (toArb(Pt (filter (\t -> t < x) xs))) (toArb(Pt (filter (\t -> t >= x) xs)))

    fromArb Empty = Pt []
    fromArb (Node x st dr) = Pt(p1 ++ [x] ++ p2)
                            where 
                                Pt p1 = fromArb (st)
                                Pt p2 = fromArb (dr)

getFromInterval :: Int -> Int -> [Int] -> [Int]
getFromInterval x y lista = filter (\t -> x <= t && t <= y) lista

getFromInterval' x y lista = do
    t <- lista
    if x <= t && t <= y then
        return t
    else
        []

newtype ReaderWriter env a = RW {getRW :: env ->(a, String)}

{-instance Monad (ReaderWriter env) where
    return va = RW (\_ -> (va, ""))
    ma >>= k = RW f
        where f env = let (va, str1) = getRW ma env
                            (vb, str2) = getRW (k va) env
                    in (vb, str1 ++ str2)-}

data PairInt = P Int Int 
                deriving Show
data MyList = L [PairInt]
                deriving Show

data Exp = I Int | Add Exp Exp | Mul Exp Exp
                deriving Show

class MyClass m where
    toExp :: m -> Exp

instance MyClass MyList where
    toExp (L []) = I 1
    toExp (L((P x y):xs)) = Mul(Add (I x)(I y)) (toExp (L xs))

