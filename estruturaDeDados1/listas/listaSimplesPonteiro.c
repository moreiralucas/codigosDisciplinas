#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct NoListaInt{
	int chave;
	struct NoListaInt *prox;
} NoListaInt;

typedef NoListaInt *ListaInt;

void inicializa (ListaInt *l);
_Bool consulta (ListaInt l, int x);
_Bool insere (ListaInt *l, int x);
void retira (ListaInt *l, int x);
void imprlista (ListaInt l);

int main(){
	ListaInt ListaSimples;
	int parada=9;
	
	while (parada != 0){
		printf ("\n1. Inicializar Lista\n");
		printf ("2. Consultar Lista\n");
		printf ("3. Inserir na Lista\n");
		printf ("4. Retirar da Lista\n");
		printf ("5. Imprimir Lista\n\n");
		printf ("Digite sua opcao: ");
		scanf ("%d", &parada);
		
		if (parada==1){
			inicializa (&ListaSimples);
			printf ("Lista incializada\n\n");
		}
		if (parada==2){
			int numero;
			
			printf ("Digite o numero para consulta: ");
			scanf ("%d", &numero);
			if (consulta(ListaSimples, numero))
				printf ("Numero na lista.\n\n");
			else
				printf ("Numero não esta na lista.\n\n");
		}
		if (parada==3){
			int numero;
			
			printf ("Digite numero para insercao na lista: ");
			scanf ("%d", &numero);
			if (insere (&ListaSimples, numero))
				printf ("Numero inserido na lista.\n\n");
			else
				printf ("Erro na inserção.\n\n");
		}
		if (parada==4){
			int numero;
			
			printf ("Digite numero para retirada da lista: ");
			scanf ("%d", &numero);
			retira (&ListaSimples, numero);
			printf ("Numero retirado da lista.\n\n");
		}
		if (parada==5)
		imprlista (ListaSimples);
	}
	return 0;
}

void inicializa (ListaInt *l){
	*l= NULL;
}

_Bool consulta (ListaInt l, int x){
	NoListaInt *p;
	
	for (p=l; (p!=NULL)&&(p->chave!=x); p=p->prox);
	if (p==NULL)
		return false;
	return true;
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

void imprlista (ListaInt l){
	NoListaInt *p;
	
	for (p=l; (p!=NULL); p=p->prox)
		printf ("%d \n", p->chave);
}
