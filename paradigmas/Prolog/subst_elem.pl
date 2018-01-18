/*subst_elem(_,_,[],[]).
subst_elem(E1,E2,[E1|Y],[E2|Y]).
subst_elem(E1,E2,[X|Y],[X|B]):-
    subst_elem(E1,E2,Y,B).*/
subst_elem(_,[],[]).
subst_elem(E1,[E1|Y], NL):-
    subst_elem(E1,[xxxx|Y],NL).
subst_elem(E1,[X|Y],[X|B]):-
    E1\==X,
    subst_elem(E1,Y,B).

/*subst_elem(E1,[X|Y],Y):-
    subst_elem(E1,Y,W).*/

/*
subst_elem(_,[],[]).
subst_elem(E1,[E1|Y],[xxxx|W]):-
    subst_elem(E1,Y,W).
*/

/*    subst_elem(E1,E2,Y,B). */

/*
Substituir um elemento de uma lista por um outro elemento:
substitui (X, Y, Lista, Lista_resultante)

 */
