%implicatie:
vars(X,[X]):-atom(X).
vars(non(X),L):-vars(X,L).
vars(imp(X,Y), Lf):-vars(X, L1), vars(Y, L2), union(L1, L2, Lf).

%si

vars(si(X,Y), Lf):- vars(X,L1), vars(Y, L2), union(L1, L2, Lf).

%sau

vars(sau(X,Y), Lf):- vars(X,L1), vars(Y, L2), union(L1, L2, Lf).

%intoarcere_valoare

val(V, [(V,E)|L], E).
val(V,[_|L],R):-val(V, L, R).

%ex3

bnon(0, 1).
bnon(1, 0).
bsi(0, 0, 0).
bsi(0, 1, 0).
bsi(1, 0, 0).
bsi(1, 1, 1).
bsau(0, 0, 0).
bsau(0, 1, 1).
bsau(1, 0, 1).
bsau(1, 1, 1).
bimp(X, Y, Z) :- bnon(X,NX), bsau(NX, Y, Z).

%ex4
eval(V, E, A):- val(V,E,A).
eval(non(X), E, A):- eval(X,E,B), bnon(B,A).
eval(si(X,Y), E, A):- eval(X,E,B), eval(Y,E,C), bsi(B,C,A).
eval(sau(X,Y),E,A):- eval(X,E,B), eval(Y,E,C), bsau(B,C,A).
eval(imp(X,Y),E,A):- eval(X,E,B), eval(Y,E,C), bimp(B,C,A).

%ex5
evals(_,[],[]).
evals(X,[E|Es], [A|As]):- eval(X,E,A), evals(X, Es, As).

%ex6
adauga(_,[],[]).
adauga(X, [H|T], [[(X,1)|H], [(X,0)|H]|Z]):-adauga(X, T, Z).

evs([],[[]]).
evs([X|H],W) :- evs(H,V), adauga(X, V, W).

all_evals(X, R):-vars(X,Lvar), evs(Lvar,Etoate), evals(X,Etoate,R).

%ex8
all_ones([]).
all_ones([1|T])-all_ones(T).
taut(X):-all_evals(X,Y), all_ones(y).
