/* Retirar todas as ocorrências de um elemento de uma lista */
retirar_ocor(_,[],[]).
retirar_ocor(E,[E|Y],NL):-
	retirar_ocor(E,Y,NL).
retirar_ocor(E,[X|Y],[X|W]):-
	E\==X,
	retirar_ocor(E,Y,W).
/* retirar_ocor(a,[a,b,d,c,a,a,f],W). */
