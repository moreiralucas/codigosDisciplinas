#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct NoListaInt{
	int chave;
	struct NoListaInt *prox;
} NoListaInt;

typedef NoListaInt *ListaInt;

ListaInt q;
NoListaInt *p;

void inicializa (ListaInt *l){
	*l->prox=*l;
	*l= NULL;
}

_Bool consulta (ListaInt l, int x){
	NoListaInt *p;
	
	for (p=l; (p->chave !=x) && (p->prox != l); p=p->prox);
	if (p-> == x)
		return true;
	return false;
}

_Bool insere (ListaInt *l, int x){
	NoListaInt *p;
	
	if (consulta(*l,x)&&(!(p=(NoListaInt *)malloc(sizeof(NoListaInt)))))
		return false;
	p->chave = x;
	p->prox = *l;
	*l = p;
	return true;
}

void retira (ListaInt *l, int x){
	NoListaInt *p, *q;
	
	for (p=*l, q=NULL;(p) && (p->chave != x); q=p, p=p->prox);
	if (p){
		if (!q)
			*l = p->prox;
		else
			q->prox = p->prox;
		free (p);
	}
}

int main(){
	
	return 0;
}