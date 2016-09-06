#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct NolistaInt{
	int chave;
	struct NolistaInt *prox;
}NolistaInt, *listaInt;

void inicializa(listaInt *l){
	*l=NULL;
}

//Letra A
void eliminaKEsimo(listaInt *l, int k) {
	if(l){
		NolistaInt *p, *q;
		int i;
		for(i=1, p=*l, q=NULL; (i != k) && (p); i++, q=p, p=p->prox);
		if(p)
			if(q)
				q->prox=p->prox;
			else
				*l= p->prox;
		
	}
}

//Letra B
void retiraMaior(listaInt *l){
	if(l){
		NolistaInt *p, *q;
		int maior = l->chave;
		for(p=*l, q=NULL; p; q=p, p=p->prox)
			if(p->chave >= maior){
				maior = p->chave;
				//q=p;
			}
		for(p=*l, q=NULL; (p->chave != maior) && p; q=p, p=p->prox);
		if(p){
			if(q)
				q->prox = p->prox;
			else
				*l->prox = p->prox;
		}
	}
}

//Letra C
void retiraElementos(listaInt *l, int x){
	if(l){
		NolistaInt *p, *q;
		for(p=*l, q=NULL; p; q=p, p=p->prox){
			if(p->chave == x){
				q->prox=p->prox;

			}
		}
	}
}