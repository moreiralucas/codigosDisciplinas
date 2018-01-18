/* Encontrar o maior elemento de uma lista numérica */
maior_2(X,Y,X):-
	X>Y.
maior_2(X,Y,Y):-
	Y>X.
maior([E],W).
maior([X|Y],M):- maior(Y,M1), maior_2(X,M1,M).

