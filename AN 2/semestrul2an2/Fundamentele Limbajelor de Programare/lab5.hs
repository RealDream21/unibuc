data Term = Variable String | FuncSym String [Term]
    deriving (Eq, Show)

-- returns all variables of a term
var :: Term -> [String]
var (Variable str) = [str]
var (FuncSym str sirTerm) = concatMap var sirTerm

-- substitutes, in a term, a variable by another term
subst :: Term -> String -> Term -> Term
subst (Variable a) str term
    | a == str = term
    | otherwise = Variable str
subst (FuncSym str sirTerm) str1 term = FuncSym str (map (\termen -> subst termen str1 term) sirTerm)

data Equ = Equ Term Term
    deriving Show

data StepResult = FailureS | Stopped | SetS [Equ]
    deriving Show

step1 :: [Equ] -> StepResult
step1 [] = Stopped
step1 ((Equ term1 term2): listEqu)
    | (var term1) == (var term2) = Stopped
    | otherwise = step1 listEqu

step2 :: [Equ] -> StepResult
step2 [] = Stopped
step2 ((Equ term1 term2): listEqu)
    | (var term1) /= (var term2) = FailureS
    | otherwise = step1 listEqu

step3 :: [Equ] -> StepResult
step3 = undefined

step4 :: [Equ] -> StepResult
step4 = undefined

step5 :: [Equ] -> StepResult
step5 = undefined

-- candidates for "x=t" in step 6 of the algorithm
step6cand :: [Equ] -> [Equ]
step6cand = undefined

-- substitutes in a list of equations a variable by a term EXCEPT for the equation "variable=term" (as used in step 6 of the algorithm)
substeq :: [Equ] -> String -> Term -> [Equ]
substeq = undefined

step6 :: [Equ] -> StepResult
step6 = undefined
                
onestep :: [Equ] -> StepResult
onestep es = case (step1 es) of
              SetS fs -> SetS fs
              Stopped -> case (step2 es) of
                          FailureS -> FailureS
                          Stopped -> case (step3 es) of
                                      SetS fs -> SetS fs
                                      Stopped -> case (step4 es) of
                                                  SetS fs -> SetS fs
                                                  Stopped -> case (step5 es) of
                                                              FailureS -> FailureS
                                                              Stopped ->  case (step6 es) of
                                                                           SetS fs -> SetS fs
                                                                           Stopped -> Stopped

data AllResult = Failure | Set [Equ]
    deriving Show

unify :: [Equ] -> AllResult
unify es = case (onestep es) of
                    Stopped -> Set es
                    FailureS -> Failure
                    SetS fs -> unify fs
                    
eqset1 = [Equ (Variable "z") (FuncSym "f" [Variable "x"]), Equ (FuncSym "f" [Variable "t"]) (Variable "y")]
         -- z=f(x), f(t)=y  --> should have z=f(x), y=f(t)

eqset2 = [Equ (FuncSym "f" [Variable "x", FuncSym "g" [Variable "y"]]) (FuncSym "f" [FuncSym "g" [Variable "z"], Variable "z"])]
         -- f(x,g(y))=f(g(z),z) --> should have x=g(g(y)), z=g(y)

eqset3 = [Equ (FuncSym "f" [Variable "x", FuncSym "g" [Variable "x"], FuncSym "b" []]) (FuncSym "f" [FuncSym "a" [], FuncSym "g" [Variable "z"], Variable "z"])]
          -- f(x,g(x),b)=f(a,g(z),z) --> should return failure