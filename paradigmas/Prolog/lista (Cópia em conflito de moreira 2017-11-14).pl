/*
Use: swipl -s youFile
comand: "halt." to quit
*/
/**/
/* N-ésimo elemento de uma lista */

n_esimo(1, E,[E|_]).
n_esimo(N, E,[_|Y]):-
	n_esimo(N1,E,Y),
	N is N1 + 1.

/* Número de elementos de uma lista */
no_elementos([],0).
no_elementos([X|Y],N):-
	no_elementos(Y,R),
	N is R+1.

/* Retirar a primeira ocorrência de um elemento de uma lista */
tira_elemento(E,[E|Y],Y):-!.
tira_elemento(E,[X|Y],[X|Z]):-
	tira_elemento(E,Y,Z).

/* Retirar todas as ocorrências de um elemento de uma lista */
retirar_ocor(_,[],[]).
retirar_ocor(E,[E|Y],NL):-
	retirar_ocor(E,Y,NL).
retiar_ocor(E,[X|Y],[X|W]):-
	E\==X,
	retirar_ocor(E,Y,W).

/* Retirar elementos repetidos de uma lista */
tira_elem(_,[],[]).
tira_elem(X,[X|Y],NL):-
	tira_elem(X,Y,NL).
tira_elem(X,[Z|||Y],NL):-
	tira_elem(X,Y,L),
	NL=[Z|L].
tira_rep([],[]).
tira_rep([X|Y,NL]):-
	tira_elem(X,Y,L),
	tira_rep(L,Z),
	NL = [X|Z].



/* Concatenar duas listas quaisquer */
concatena([],[],[]):-!.
concatena([],L,L):-!.
concatena(L,[],L):-!.
concatena([X|Y],NL,[X|W]):- concatena(Y,NL,W).

/* Concetena listas de listas */
concatena_lista([[]],[]):-!.
concatena_lista([X],X):-!.
concatena_lista([X|R],L):-
	concatena(X,[],L1),
	concatena_lista(R,W),
	concatena(L1,W,L).


/* Concatena invertido */
/* Não funciona */
inverte_lista([],[],[]):-!.
inverte_lista(X,[],X):-!.
inverte_lista([],X,X):-!.
inverte_lista([X|R],Y,[X|L]):-inverte_lista(Y,R,L).

concatena_invertido(X,Y,L):- concatena(Y,X,L).

/* Encontrar o maior elemento de uma lista numérica */
maior_2(X,Y,X):-
	X>Y.
maior_2(X,Y,Y):-
	Y>X.

/*  */
/*  */
/*  */
/*  */
/*  */
/*  */







