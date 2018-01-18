
/* Retirar a primeira ocorrência de um elemento de uma lista*/
tira_elemento(E,[E|Y],Y):-!.
tira_elemento(E,[X|Y],[X|Z]):-
	tira_elemento(E,Y,Z).
/* tira_elemento(a,[b,c,a,d,e,a],W). */
