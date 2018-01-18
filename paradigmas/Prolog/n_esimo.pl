/* N-ésimo elemento de uma lista */
n_esimo(1, E,[E|_]).
n_esimo(N, E,[_|Y]):-
	n_esimo(N1,E,Y),
	N is N1 + 1.
/*n_esimo(3,E,[a,b,c,d,e,f,g]).*/
