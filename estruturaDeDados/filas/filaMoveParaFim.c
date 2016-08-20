#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct NoListaint{
	int chave;
	struct NoListaint *prox;
}NoListaint;
typedef NoListaint *ListaInt;

_Bool consulta(ListaInt *l, int x);
void inicializa(ListaInt *l);
void moveParaFim(ListaInt *l, int x);


void inicializa(ListaInt *l){
	*l=NULL;
}
void moveParaFim(ListaInt *l, int x){
	ListaInt *q, *p;
	if(consulta(l, x))
	for (p=*l, q=NULL;(p) && (p->chave != x); q=p, p=p->prox);
	if(!q)
		*l = p-> prox;
	else
		q->prox = p->prox;
	q->chave = x;
	q->prox = *l;
	*l=q;
	free(p);
	free(q);
}

_Bool consulta(ListaInt *l, int x){
	NoListaInt *q;
	for(q=l; (q != NULL) && (q->chave != x); q=q->prox);
	if(p == NULL)
		return false;
	return true;
}

