oculte(_,[],[]).
oculte(E1,[E1|Y], NL):-
    oculte(E1,[xxxx|Y],NL).
oculte(E1,[X|Y],[X|B]):-
    E1\==X,
    oculte(E1,Y,B).
