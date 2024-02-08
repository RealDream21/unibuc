import Data.Functor.Product (Product(Pair))
import Data.ByteString (group)
import Data.Array.Base (bOOL_NOT_BIT)
import Data.Binary.Get (label)
import GHC.Windows (LPTSTR)
class Collection c where
  empty :: c key value
  singleton :: key -> value -> c key value
  insert
      :: Ord key
      => key -> value -> c key value -> c key value
  clookup :: Ord key => key -> c key value -> Maybe value
  delete :: Ord key => key -> c key value -> c key value
  keys :: c key value -> [key]
  keys c = [fst p | p <- toList c]
  values :: c key value -> [value]
  values c = [snd p | p <- toList c]
  toList :: c key value -> [(key, value)]
  fromList :: Ord key => [(key,value)] -> c key value
  fromList ((key, value):list) = insert key value (fromList list)

newtype PairList k v
  = PairList { getPairList :: [(k, v)] }

instance Collection PairList where
  empty = PairList []
  singleton key value = PairList [(key, value)]
  insert key value (PairList l) = PairList ((key,value):l)
  clookup key = lookup key.getPairList
  delete key (PairList l) = PairList $ filter (\t -> fst t /= key) l

data SearchTree key value
  = Empty
  | BNode
      (SearchTree key value) -- elemente cu cheia mai mica
      key                    -- cheia elementului
      (Maybe value)          -- valoarea elementului
      (SearchTree key value) -- elemente cu cheia mai mare

instance Collection SearchTree where
  empty = Empty
  singleton key value = BNode Empty key (Just value) Empty
  insert newkey newvalue = go
                    where
                      go empty = Empty
                      go (BNode left key value right)
                        | newkey > key = BNode left key value (go right)
                        | newkey < key = BNode (go left) key value right
                        | otherwise = BNode left key (Just newvalue) right
  delete delkey = go 
                where 
                  go Empty = Empty
                  go (BNode left key value right)
                    | delkey < key = BNode (go left) key value right
                    | delkey > key = BNode left key value (go right)
                    | otherwise = BNode left key Nothing right

  {-clookup lkey = go 
                where
                  go Empty = Empty
                  go (BNode left key value right)
                    | lkey < key = BNode (go left) key value right
                    | lkey > key = BNode left key value (go right)
                    | otherwise = value-}



data Punct = Pt [Int]

data Arb = Vid | F Int | N Arb Arb
          deriving Show

class ToFromArb a where
 	    toArb :: a -> Arb
	    fromArb :: Arb -> a


instance Show Punct where 
  show (Pt l) = "(" ++ show l ++ ")"


instance ToFromArb Punct where
  toArb (Pt []) = Vid
  toArb (Pt(x:xs)) = N (F x) (toArb (Pt xs))

  fromArb Vid = Pt []
  fromArb (F x) = Pt [x]
  fromArb (N l r) = Pt (p1 ++ p2)
                  where 
                    Pt p1 = fromArb l
                    Pt p2 = fromArb r

-- Pt [1,2,3]
-- (1, 2, 3)

-- Pt []
-- ()

-- toArb (Pt [1,2,3])
-- N (F 1) (N (F 2) (N (F 3) Vid))
-- fromArb $ N (F 1) (N (F 2) (N (F 3) Vid)) :: Punct
--  (1,2,3)
data Geo a = Square a | Rectangle a a | Circle a
    deriving Show

class GeoOps g where
  perimeter :: (Floating a) => g a -> a
  area :: (Floating a) =>  g a -> a


instance GeoOps Geo where
  perimeter (Square a) = 4 * a
  perimeter (Rectangle l l1) = 2 * l + 2 * l1
  perimeter (Circle r) = 2 * pi * r

  area (Square a) = a * a
  area (Rectangle l l1) = l * l1
  area (Circle r) = pi*r*r

instance (Eq a, Floating a) => Eq (Geo a) where
  (==) g1 g2 = perimeter g1 == perimeter g2



-- ghci> pi
-- 3.141592653589793

