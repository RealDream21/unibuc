data LambdaTerm = Var String | Lam String LambdaTerm | App LambdaTerm LambdaTerm
    deriving Show

-- union of two sets represented as lists
union2 :: (Eq a) => [a] -> [a] -> [a]
union2 x y = x ++ [z | z <- y, notElem z x]

-- variables of a lambda term
var :: LambdaTerm -> [String]
var (Var str) = [str]
var (Lam str lt) = var lt `union2` [str]
var (App lt1 lt2) = union2 (var lt1) (var lt2)

-- free variables of a lambda term
fv :: LambdaTerm -> [String]
fv (Var str) = [str]
fv (Lam str lt) = [y | y <- fv lt, y /= str]
fv (App m n) = union2 (fv m) (fv n)

-- an endless reservoir of variables
freshvarlist :: [String]
freshvarlist = map (("x" ++). show) [0..]

-- fresh variable for a term
freshforterm :: LambdaTerm -> String
freshforterm t = head [x | x <- freshvarlist, x `notElem` var t]

-- the substitution operation for lambda terms
subst :: LambdaTerm -> String -> LambdaTerm -> LambdaTerm
subst (Var y) x n
    | x == y = n
    | otherwise = Var y
subst (p `App` q) x n = subst p x n `App` subst q x n
subst (Lam y p) x n
    | x == y = Lam x p
    | y `notElem` fv n = Lam y (subst p x n)
    | otherwise = 
        let z = freshforterm (Lam x (App n p )) in
        Lam z $ subst(subst p y (Var z)) x n

test_subst = subst (Lam "x" (App (Var "y") (Var "x"))) "y" (Var "x")

-- beta reduction in one step
beta1 :: LambdaTerm -> [LambdaTerm]
beta1 (Var x) = []
beta1 ((Lam x m) `App` n) =
    subst m x n
    : [Lam x m `App`n' | n' <- beta1 n]
    ++ [Lam x m' `App` n | m' <- beta1 m]
beta1 (Lam x m) = map(Lam x) (beta1 m)
beta1(m `App` p) = 
    [m `App` p' | p' <- beta1 p] ++ [m' `App` p | m' <- beta1 m]


-- checks whether a term is in normal form
nf :: LambdaTerm -> Bool
nf = null . beta1

data TermTree = TermTree LambdaTerm [TermTree]
    deriving Show

-- the beta-reduction tree of a lambda term
reductree :: LambdaTerm -> TermTree
reductree t = TermTree t (map reductree (beta1 t))

-- depth-first traversal of all the nodes in a term tree
df_all :: TermTree -> [LambdaTerm]
df_all (TermTree t l) = t : concatMap df_all l

-- just the leaves
df_leaves :: TermTree -> [LambdaTerm]
df_leaves = filter nf . df_all

-- the left-most outer-most reduction of a term
reduce :: LambdaTerm -> LambdaTerm
reduce = head . df_leaves . reductree

term1 = App (App (Lam "x" (Lam "y" (App (Var "x") (Var "y")))) (Var "z")) (Var "w")
term2 = App (Lam "x" (App (Lam "y" (Var "x")) (Var "z"))) (Var "w")

test_beta1 = df_leaves (reductree term1)
test_beta2 = df_leaves (reductree term2)

-- a branch of given length in a tree
branch :: Int -> TermTree -> Maybe [LambdaTerm]
branch 0 (TermTree t _) = Just [t]
branch n (TermTree t l) = 
    case mapMaybe(branch (n - 1)) l of
        [] -> Nothing
        (b: )

                                
testbranch1 = branch 2 (reductree term1)
                                
testbranch2 = branch 3 (reductree term1)

term_o = Lam "x" (App (Var "x") (Var "x"))
term_O = App term_o term_o

testO = reduce term_O -- should not terminate

term_b = App (App (Lam "x" (Lam "y" (Var "y"))) term_O) (Var "z")

testb = reduce term_b -- should terminate
                                
testbranch3 = branch 10 (reductree term_b)

-- Church numeral of a number
church :: Int -> LambdaTerm
church n = undefined

-- convert from Church numeral back to number
backch :: LambdaTerm -> Int
backch = undefined

-- lambda term for successor
tsucc :: LambdaTerm 
tsucc = undefined

testsucc = backch ((reduce (App tsucc (church 7))))

-- lambda term for addition
tadd :: LambdaTerm
tadd = undefined

testadd = backch ((reduce (App (App tadd (church 7)) (church 8))))
