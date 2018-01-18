oculte(_,[],[]).
oculte(E1,[E1|Y], NL):-
    oculte(E1,[xxxx|Y],NL).
oculte(E1,[X|Y],[X|B]):-
    E1\==X,
    oculte(E1,Y,B).

oculte2([],L,L).
oculte2([H1|T1],L2,W):- oculte2(T1,L2,W), oculte(T1,W,NL).
