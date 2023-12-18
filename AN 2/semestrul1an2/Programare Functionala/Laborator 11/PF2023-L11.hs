{-
class Functor f where
fmap : : ( a -> b ) -> f a -> f b
-}

newtype Identity a = Identity a
instance Functor Identity where
    fmap g (Identity a) = Identity (g a)

data Pair a = Pair a a
instance Functor Pair where
    fmap g (Pair a a1) = Pair (g a) (g a1)

data Constant a b = Constant b
instance Functor (Constant a) where
    fmap g (Constant b) = Constant (g b)

data Two a b = Two a b
instance Functor (Two a) where
    fmap g (Two a b) = Two a (g b)

data Three a b c = Three a b c
instance Functor (Three a b) where
    fmap g (Three a b c) = Three a b (g c)

data Three' a b = Three' a b b
instance Functor (Three' a) where
    fmap g (Three' a b1 b2) = Three' a (g b1) (g b2)

data Four a b c d = Four a b c d
instance Functor (Four a b c) where
    fmap g (Four a b c d) = Four a b c (g d)

data Four'' a b = Four'' a a a b
instance Functor (Four'' a) where
    fmap g (Four'' a1 a2 a3 b) = Four'' a1 a2 a3 (g b)

data Quant a b = Finance | Desk a | Bloor b
instance Functor (Quant a) where
    fmap g Finance = Finance
    fmap g (Desk a) = Desk a
    fmap g (Bloor b) = Bloor (g b)

data LiftItOut f a = LiftItOut (f a)
instance Functor f => Functor ( LiftItOut f) where
    fmap g (LiftItOut fa) = LiftItOut (fmap g fa) 

data Parappa f g a = DaWrappa (f a) (g a)
instance (Functor f, Functor g) => Functor (Parappa f g ) where
    fmap f (DaWrappa fa ga) = DaWrappa (fmap f fa) (fmap f ga)

data IgnoreOne f g a b = IgnoringSomething (f a) (g b)
instance (Functor g) => Functor (IgnoreOne f g a) where
    fmap f (IgnoringSomething fa gb) = IgnoringSomething fa (fmap f gb)

data Notorious g o a t = Notorious (g o) (g a) (g t)
instance (Functor f) => Functor (Notorious f o a) where
    fmap f (Notorious go ga gt) = Notorious go ga (fmap f gt)

data GoatLord a = NoGoat | OneGoat a | MoreGoats (GoatLord a) (GoatLord a) (GoatLord a)
instance Functor GoatLord where
    fmap _ NoGoat = NoGoat
    fmap f (OneGoat a) = OneGoat (f a)
    fmap f (MoreGoats a b c) = MoreGoats (fmap f a) (fmap f b) (fmap f c)

data TalkToMe a = Halt | Print String a | Read (String -> a)
instance Functor TalkToMe where
    fmap _ Halt = Halt
    fmap f (Print x a) = Print x (f a)
    fmap f (Read x) = Read (f . x)
