#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct NolistaInt{
	int chave;
	struct NolistaInt *prox, *ant;
}NolistaInt, *ListaInt ; 

void inicializa (ListaInt *l){
	*l= NULL;
}
_Bool consulta(ListaInt l, int x){
	NolistaInt *p;
	for(p=l; (p != NULL) && (p->chave != x); p=p->prox);
	if(p == NULL)
		return false;
	return true;
}
_Bool insere(ListaInt *l, int x){
	NolistaInt *p;
	//Verifica se já existe ou se a lista está cheia
	if ((consulta(*l,x)) || (!(p =(NolistaInt *)malloc(sizeof(NolistaInt)))))
		return false;
	p-> chave = x;
	p-> prox = *l;
	p-> ant = NULL;
	if(*l)
		*l->ant=p;
	*l=p;
	return true;
}
void retira(ListaInt *l, int x){
	NolistaInt *p;
	for (p = *l; p && (p->chave != x); p=p->prox);
	if(p){
		if(p->ant && p->prox){
			p->ant->prox = p->prox;
			p->prox->ant = p->ant;
		}else if(!(p->prox) && (p-> ant))
			p->ant->prox = NULL;
		else if((p->prox) && !(p->ant))
			p->prox->ant = NULL;
		else
			*l = NULL;
		free(p);
	}
	
}
