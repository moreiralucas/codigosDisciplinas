#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct NoFilaInt{
	int chave;
	struct NoFilaInt *prox;
}NoFilaInt;
typedef struct{
	NoFilaInt *prim, *ult;	
}FilaInt;

void inicializa(FilaInt *l){
	*l = NULL;
}
_Bool consulta(FilaInt l, int x){
	NoFilaInt *p;
	for(p=l;(p != NULL) && (p->chave != x); p=p->prox);
	if(p == NULL) return false;
	return true;
}
_Bool enfileira(FilaInt *l, int x){
	NoFilaInt *p;
	if(consulta(*l,x) && (!(p=(NoFilaInt *)malloc(sizeof(NoFilaInt)))))
		return false;
	p->chave = x;
	p->prox = *l;
	*l=p;
	return true;
}
_Bool desenfileira(FilaInt *l){
	NoFilaInt *p, *q;
	if(!p)
		return false;
	for (p=*l, q=NULL; (p->prox); q=p, p=p->prox);
	q->prox = NULL;
	return true;

}
