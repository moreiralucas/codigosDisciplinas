#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct NolistaInt{
	int chave;
	struct NolistaInt *prox, *ant;
}NolistaInt, *ListaInt ; 

void inicializa(ListaInt *l){
	*l=NULL;
}

void EliminaKEsimo(ListaInt *l, int k){
	if(l){
		NolistaInt *p, *q, *u;
		
	}
}