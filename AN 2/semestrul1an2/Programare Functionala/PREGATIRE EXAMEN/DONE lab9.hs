import Text.XHtml (base, background)
data Tree = Empty  -- arbore vid
   | Node Int Tree Tree Tree -- arbore cu valoare de tip Int in radacina si 3 fii
      
-- extree :: Tree
-- extree = Node 4 (Node 5 Empty Empty Empty) 
--                 (Node 3 Empty Empty (Node 1 Empty Empty Empty)) Empty

class ArbInfo t where
  level :: t -> Int -- intoarce inaltimea arborelui; pt un arbore vid
                      -- se considera ca are inaltimea 0
  sumval :: t -> Int -- intoarce suma valorilor din arbore
  nrFrunze :: t -> Int -- intoarce nr de frunze al arborelui
-- level extree
-- 3
-- sumval extree
-- 13
-- nrFrunze extree
-- 2
instance ArbInfo Tree where
  level Empty = 0
  level (Node key st m dr) = 1 + maximum([level st, level dr, level m])
  sumval Empty = 0
  sumval (Node key st m dr) = key + (sumval st) + (sumval m) + sumval(dr)
  nrFrunze Empty = 0
  nrFrunze (Node key Empty Empty Empty) = 1
  nrFrunze (Node key st m dr) = nrFrunze st + nrFrunze m + nrFrunze dr

class Scalar a where
  zero :: a
  one :: a
  adds :: a -> a -> a
  mult :: a -> a -> a
  negates :: a -> a
  recips :: a -> a

instance Scalar Float where
  zero = 0
  one = 1
  adds a b = a + b
  mult a b = a * b 
  negates a = -1 * a 
  recips a = if a /= 0 then 1/a 
              else error "EROARE"


class (Scalar a) => Vector v a where
  zerov :: v a
  onev :: v a
  addv :: v a -> v a -> v a -- adunare vector
  smult :: a -> v a -> v a  -- inmultire cu scalare
  negatev :: v a -> v a -- negare vector

data Vector2D a = Vector2D a a deriving (Eq, Show)

instance (Scalar a) => Vector Vector2D a where
  zerov = Vector2D zero zero
  onev = Vector2D one one
  addv (Vector2D a1 b1) (Vector2D a2 b2) = Vector2D (adds a1 a2) (adds b1 b2)
  smult a (Vector2D a1 b1) = Vector2D (mult a1 a) (mult b1 a)
  negatev (Vector2D a1 b1) = Vector2D (negates a1) (negates b1)

data Vector3D a = Vector3D a a a deriving(Eq, Show)

instance (Scalar a) => Vector Vector3D a where
  zerov = Vector3D zero zero zero
  onev = (Vector3D one one one)
  addv (Vector3D a1 a2 a3) (Vector3D b1 b2 b3) = Vector3D (adds a1 b1) (adds a2 b2) (adds a3 b3)
  smult a (Vector3D a1 a2 a3) = Vector3D (mult a a1) (mult a a2) (mult a a3)
  negatev (Vector3D a b c) = Vector3D (negates a) (negates b) (negates c)