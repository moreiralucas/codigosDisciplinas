#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MTAMFILA 100

typedef struct fila{
	int chaves[MTAMFILA];
	int begin;
	int nElems;
} FilaInt;

void inicializa (FilaInt *l){
	l->nElems = f->begin = 0;
}

_Bool consulta (FilaInt l, int x){
	int i;
	if(!(l.nElems)) return false;
	for (i=l.begin; (i < l.begin + l.nElems )&&(l.chaves[i]!=x); i++);
	if (i== (l.begin + l.nElems))
		return false;
	return true;
}
_Bool enfileira (FilaInt *l, int x){
	if (l->begin==MTAMFILA)
		return false;
	l->chaves[(l->begin+l.nElems) % MTAMFILA]= x;
	l->nElems++;
	return true;
}

_Bool desenfileira (FilaInt *l){
	if(l->nElems == 0)
		return false;
	if(l->begin == MTAMFILA-1){
		l->begin = 0;
	}
	else{
		l->begin++;
	}
	return true;
}
