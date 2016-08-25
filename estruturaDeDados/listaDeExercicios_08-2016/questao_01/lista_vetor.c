#define MAX 50;

typedef struct ListaInt{
	int chave[MAX];
	int nElems;
} ListaInt;

void inicializa(ListaInt *l){
	l->nElems=0;
}

//Letra A
int menor(ListaInt *l){
	if(!l->nElems)
		return 0;
	int i;
	int menor = l->chave[0];
	for (i = 1; i < l->nElems; ++i)
		if(l->chave[i] < menor)
			menor= l->chave[i];
	return menor;
}

//Letra B
int nImpares(ListaInt *l){
	int i;
	int cont=0;
	for (i = 0; i < l->nElems; ++i)
		if(l->chave[i]%2)
			cont++;
	return cont;
}

//Letra C
double media(ListaInt *l){
	if(!l->nElems)
		return 0;
	int i;
	int cont = 0;
	for (i = 0; i < l->nElems; ++i)
		cont += l->chave[i];
	return cont/l->nElems;
}

//Letra D
int somaValores(ListaInt *l){
	if(!l->nElems)
		return 0;
	int i;
	int cont = 0;
	for (i = 0; i < l->nElems; ++i)
		cont += l->chave[i];
	return cont;
}

//Letra E
int somaQuadradosValores(ListaInt *l){
	if(!l->nElems)
		return 0;
	int i;
	int cont = 0;
	for (i = 0; i < l->nElems; ++i)
		cont += (l->chave[i] * l->chave[i]);
	return cont;
}