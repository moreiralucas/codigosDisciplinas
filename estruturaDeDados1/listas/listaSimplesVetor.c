#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MTAMLISTA 10

typedef struct{
	int chaves[MTAMLISTA];
	int nelems;
} ListaInt;

void inicializa (ListaInt *l);
_Bool consulta (ListaInt l, int x);
_Bool insere (ListaInt *l, int x);
void retira (ListaInt *l, int x);
void imprlista (ListaInt l);

int main(){
	ListaInt ListaSimples;
	int parada=99;
	
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
				printf ("Lista cheia.\n\n");
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
	l->nelems = 0;
}

_Bool consulta (ListaInt l, int x){
	int i;
	
	for (i=0; (i<l.nelems)&&(l.chaves[i]!=x); i++);
	if (i==l.nelems)
		return false;
	return true;
}

_Bool insere (ListaInt *l, int x){
	
	if (consulta(*l,x))
		return true;
	if (l->nelems==MTAMLISTA)
		return false;
	l->chaves[l->nelems]= x;
	l->nelems++;
	return true;
}

void retira (ListaInt *l, int x){
	int i;
	
	for (i=0;(i<l->nelems)&&(l->chaves[i]!=x); i++);
	if (l->chaves[i]==x){
		l->chaves[i]=(l->chaves[l->nelems-1]);
		l->nelems--;
	}
}
void imprlista (ListaInt l){
	int i;
	
	for (i=0; i<l.nelems; i++)
		printf ("%d  \n", l.chaves[i]);	
}
