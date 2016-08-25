#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct NolistaInt{
	int chave;
	struct NolistaInt *prox;
}NolistaInt, *listaInt;

void inicializa(listaInt *l){
	l=NULL;
}

void eliminaKEsimo(listaInt *l, int k) {
	if(l){
		NolistaInt *p, *q, *u;
		int i;
		for(i=1, p=*l, q=NULL; (i != k) && p; i++, q=p, p=p->prox);
		if(p){
			c = p->chave;
			if(q)
				q->prox=p->prox;
			else
				*l= p->prox;
		}

	}
}
void retiraMaior(listaInt *l){
	if(l){
		NolistaInt *p, *q, *u;
		q=NULL;
		int maior = l->chave;
		for(p=*l; p; p=p->prox)
			if(p->chave > maior){
				maior = p->chave;
				q=p;
			}
		if(q)
			q->prox = p->prox;
	}
}

void retiraElementos(listaInt *l, int x)