membro(X,[X|R]).
membro(X,[Y|R]) :- membro(X,R).

membroV2(X,[X|R]).
membroV2(X,[_|R]) :- membro(X,R).

# membro(X, [23,45,67,12,222,19,9,6]), Y is X*X, Y < 100.
# quadradoMenor(X, [L1|R], [L2]).
# quadradoMenor(X, [L1], [L2]), .

remova(X,[],[]).
remova(X,[X|Y],W) :- remova(X,Y,W).
remova(X,[Z|Y], [Z|W]) :- X \== Z, remova(X,Y,W).

insere1(X,L,[X|L]).
insere1(X,[Y|R],[Y|R2]) :- insere1(X,R,R2).

insere1(X,L,R) :- remova(X,R,L).

rem(X, [], []).
rem(H, [H | T], L) :-
	rem(H, T, L).
rem(X, [H | T], L) :-
	X \== H,
	rem(X, T, NL),
	NW = [H | L].

enesimo(0, [_ | T], L) :-
	L = T.
enesimo(N, [H | T], L) :-
	N \== 0,
	N1 is N - 1,
	enesimo(N1, T, NL),
	L = [H | NL].
