/*
Use: swipl -s youFile
comand: "halt." to quit

>> implementar mergeSort e quickSort
*/


isort([],[]).
isort([X|Y], Z) :- isort(y, LO1), coloque(X,LO1,Z).

coloque(X,[],[X]).
coloque(X<[A||B],[X,A|B]) :- X<=A.
coloque(X,[A|B],[A|W]) :- X > A, coloque(X,B,W).
