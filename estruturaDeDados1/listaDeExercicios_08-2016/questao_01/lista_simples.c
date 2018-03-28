#define MAX 50

typedef struct NolistaInt{
	int chave;
	struct NolistaInt *prox;
}NolistaInt, *ListaInt;

void inicializa(ListaInt *l){
	l=NULL;
}

//Letra A
int menor(ListaInt *l){
	if(!l)
		return 0;
	NolistaInt *p;
	int menor = l->chave;
	for(p=*l; (p != NULL); p=p->prox)
		if(p->chave < menor) menor = p->chave;
	return menor;
}

//Letra B
int nImpares(ListaInt *l){
	NolistaInt *p;
	int cont=0;
	for(p=*l; q; q=q->prox)
		if(q->chave%2)
			cont++;
	return cont;
}

//Letra C
double media(ListaInt *l){
	if(!l)
		return 0;
	NolistaInt *p;
	int i, cont=0;
	for(p=*l, i=0; p; p=p->prox, i++)
		cont+=p->chave;
	return cont/i;
}

//Letra D
int somaValores(ListaInt *l){
	if(!l)
		return 0;
	NolistaInt *p;
	int cont=0;
	for(p=*l; p; p=p->prox)
		cont+=p->chave;
	return cont;
}

//Letra E
int somaQuadradosValores(ListaInt *l){
	if(!l)
		return 0;
	NolistaInt *p;
	int cont=0;
	for(p=*l; p; p=p->prox)
		cont+=p->chave * p->chave;
	return cont;
}
