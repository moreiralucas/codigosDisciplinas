/* Número de elementos de uma lista */
no_elementos([],0).
no_elementos([X|Y],N):- 
	no_elementos(Y,R),
	N is R+1.
/*no_elementos([1,2,3,4],N).*/
