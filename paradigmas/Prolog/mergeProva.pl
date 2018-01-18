
merg([X|Y],[],[X|Y]):-!.
merg([],[X|Y],[X|Y]):-!.

merg([X|Y],[U|V],[X|Z]):-
    merg(Y,[U|V],Z).

merg([X|Y],[U|V],[U|Z]):-
    merg([X|Y],V,Z).



    /* merg([1,2,3],[a,b],X). */
