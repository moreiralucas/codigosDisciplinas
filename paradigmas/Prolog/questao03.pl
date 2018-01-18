intercala(X,Y,1,X).
intercala(X,Y,N,L):-
    N is N - 1,
    intercala(X,Y,N,[X|W]),
    N is N - 1,
    intercala(X,Y,N,[Y|Q]).

/*no_elementos([],0).
no_elementos([X|Y],N):-
	no_elementos(Y,R),
	N is R+1.
*/


/*

oculte(_,[],[]).
oculte(E1,[E1|Y], NL):-
    oculte(E1,[xxxx|Y],NL).
oculte(E1,[X|Y],[X|B]):-
    E1\==X,
    oculte(E1,Y,B).

oculte2([],[],[]).
oculte2([H1|T1],L2,W):- oculte(H1,L2,W), oculte2(T1,W,NL).

 */
