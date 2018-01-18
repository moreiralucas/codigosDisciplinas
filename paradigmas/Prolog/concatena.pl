/* Concatenar duas listas quaisquer */
concatena([],[],[]):-!.
concatena([],L,L):-!.
concatena(L,[],L):-!.
concatena([X|Y],NL,[X|W]):- concatena(Y,NL,W).
/* concatena([a,b,c],[e,d],W). */


/* Concetena listas de listas */
concatena_lista([[]],[]):-!.
concatena_lista([X],X):-!.
concatena_lista([X|R],L):-
	concatena(X,[],L1),
	concatena_lista(R,W),
	concatena(L1,W,L).


/* Concatena invertido */
inverte_lista([],[],[]):-!.
inverte_lista(X,[],X):-!.
inverte_lista([],X,X):-!.
inverte_lista([X|R],Y,[X|L]):-inverte_lista(Y,R,L).
/*
inverte_lista([a,b,c],[d,e,f],W).
W = [a, d, b, e, c, f].
*/

concatena_invertido(X,Y,L):- concatena(Y,X,L).
/* concatena_invertido([a,b,c],[d,e,f],W) */
