import Text.XHtml (base, abbr)
import Control.Monad.Trans.Accum (look)
data Expr = Const Int -- integer constant
          | Expr :+: Expr -- addition
          | Expr :*: Expr -- multiplication
           deriving Eq


           
instance Show Expr where
  show (Const x) = show x
  show (e1 :+: e2) = "(" ++ show e1 ++ " + "++ show e2 ++ ")"
  show (e1 :*: e2) = "(" ++ show e1 ++ " * "++ show e2 ++ ")"           

evalExp :: Expr -> Int
evalExp (Const a) = a
evalExp (e1 :+: e2) = evalExp e1 + evalExp e2
evalExp (e1 :*: e2) = evalExp e1 * evalExp e2

exp1 = ((Const 2 :*: Const 3) :+: (Const 0 :*: Const 5))
exp2 = (Const 2 :*: (Const 3 :+: Const 4))
exp3 = (Const 4 :+: (Const 3 :*: Const 3))
exp4 = (((Const 1 :*: Const 2) :*: (Const 3 :+: Const 1)) :*: Const 2)
test11 = evalExp exp1 == 6
test12 = evalExp exp2 == 14
test13 = evalExp exp3 == 13
test14 = evalExp exp4 == 16

data Operation = Add | Mult deriving (Eq, Show)

data Tree = Lf Int -- leaf
          | Node Operation Tree Tree -- branch
           deriving (Eq, Show)

evalArb :: Tree -> Int
evalArb (Lf a) = a 
evalArb (Node Add t1 t2) = (evalArb t1) + (evalArb t2)
evalArb (Node Mult t1 t2) = (evalArb t1) * (evalArb t2)

arb1 = Node Add (Node Mult (Lf 2) (Lf 3)) (Node Mult (Lf 0)(Lf 5))
arb2 = Node Mult (Lf 2) (Node Add (Lf 3)(Lf 4))
arb3 = Node Add (Lf 4) (Node Mult (Lf 3)(Lf 3))
arb4 = Node Mult (Node Mult (Node Mult (Lf 1) (Lf 2)) (Node Add (Lf 3)(Lf 1))) (Lf 2)

test21 = evalArb arb1 == 6
test22 = evalArb arb2 == 14
test23 = evalArb arb3 == 13
test24 = evalArb arb4 == 16

expToArb :: Expr -> Tree
expToArb (Const a) = (Lf a)
expToArb (e1 :+: e2) = Node Add (expToArb e1) (expToArb e2)
expToArb (e1 :*: e2) = Node Mult (expToArb e1) (expToArb e2)

data IntSearchTree value
  = Empty
  | BNode
      (IntSearchTree value)     -- elemente cu cheia mai mica
      Int                       -- cheia elementului
      (Maybe value)             -- valoarea elementului
      (IntSearchTree value)     -- elemente cu cheia mai mare
  
lookup' :: Int -> IntSearchTree value -> Maybe value
lookup' a Empty = Nothing
lookup' a (BNode left key val right)
      | (a < key) = lookup' a left
      | a > key = lookup' a right
      | otherwise = val

keys ::  IntSearchTree value -> [Int]
keys Empty = []
keys (BNode left key val right) = (keys left) ++ [key] ++ (keys right)

values :: IntSearchTree value -> [Maybe value]
values Empty = []
values (BNode left key val right) = (values left) ++ [val] ++ (values right)

insert :: Int -> value -> IntSearchTree value -> IntSearchTree value
insert key value Empty = (BNode Empty key (Just value) Empty) 
insert newkey newvalue (BNode left key val right)
            | (newkey < key) = BNode (insert newkey newvalue left) key val right
            | (newkey > key) = BNode left key val (insert newkey newvalue right)
            | otherwise = (BNode Empty newkey (Just newvalue) Empty)


delete :: Int -> IntSearchTree value -> IntSearchTree value
delete _ Empty = Empty
delete delkey (BNode left key val right)
        | (delkey < key) = (BNode (delete delkey left) key val right)
        | (delkey > key) = (BNode left key val (delete delkey right))
        | otherwise = BNode left key Nothing right

toList :: IntSearchTree value -> [(Int, Maybe value)]
toList Empty = []
toList (BNode left key val right) = (toList left) ++ [(key, val)] ++ (toList right)

fromList :: [(Int, value)] -> IntSearchTree value 
fromList [] = Empty
fromList ((key,val):xs) = insert key val (fromList xs)

printTree :: IntSearchTree value -> String
printTree Empty = ""
printTree (BNode left key val right) = "(" ++ printTree left ++ ")" ++ show key ++ "(" ++ printTree right ++ ")"
