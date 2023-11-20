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
  fromList [] = empty
  fromList ((key,val):list) = insert key val (fromList list)

newtype PairList k v
  = PairList { getPairList :: [(k, v)] }

instance Collection PairList where
  empty = PairList []
  singleton key value = PairList [(key, value)]
  clookup key = lookup key.getPairList
  delete k (PairList l) = PairList $ filter((/=k).fst) l
  insert k v (PairList l) = PairList $ (k, v): filter ((/=k).fst) l

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
  insert k v = go
            where 
            go Empty = singleton k v
            go (BNode t1 k1 v1 t2)
              | k == k1 = BNode t1 k1 (Just v) t2
              | k < k1 = BNode (go t1) k1 v1 t2
              | otherwise = BNode t1 k1 v1 (go t2)
  delete k = go
            where 
            go Empty = Empty
            go (BNode t1 k1 v1 t2)
              | k == k1 = BNode t1 k1 Nothing t2
              | k < k1 = BNode (go t1) k1 v1 t2
              | otherwise = BNode t1 k1 v1 (go t2)
  {-clookup k = go
            where
            go Empty = Empty
            go (BNode t1 k1 v1 t2)
              | k == k1 = (Just v1)
              | k < k1 = BNode (go t1) k1 v1 t2
              | otherwise = BNode t1 k1 v1 (go t2)-}

data Punct = Pt [Int]

data Arb = Vid | F Int | N Arb Arb
          deriving Show

class ToFromArb a where
 	    toArb :: a -> Arb
	    fromArb :: Arb -> a

instance ToFromArb Punct where
  toArb(Pt[]) = Vid
  toArb(Pt(x:xs)) = N (F x)(toArb(Pt xs))    

  fromArb Vid = Pt []
  fromArb (F x) = Pt [x]
  fromArb (N l r) = Pt(p1 ++ p2)
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

-- ghci> pi
-- 3.141592653589793

