/*
Use: swipl -s youFile
comand: "halt." to quit

*/
fatorial1(0,1).
fatorial1(N,F) :-
	N>0,
	N1 is N-1,
	fatorial1(N1,F1),
	F is N * F1.

fatorial2(0,F,F).
fatorial2(N,A,F) :-
	N>0,
	A1 is N*A,
	N1 is N -1,
	fatorial2(N1,A1,F).
