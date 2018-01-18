/* Retirar elementos repetidos de uma lista */
tira_elem(_,[],[]).
tira_elem(X,[X|Y],NL):-
	tira_elem(X,Y,NL).
tira_elem(X,[Z|Y],NL):-
	tira_elem(X,Y,L),
	NL=[Z|L].
tira_rep([],[]).
tira_rep([X|Y],NL):-
	tira_elem(X,Y,L),
	tira_rep(L,Z),
	NL = [X|Z].

/*  tira_rep([a,b,c,a,b,c,a,b,c],W). */
