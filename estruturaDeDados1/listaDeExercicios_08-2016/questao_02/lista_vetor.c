#define MAX 100
typedef struct listaInt{
	int chave[MAX];
	int nElems;
}listaInt;

void inicializa(listaInt *l){
	l->nElems = 0;
}

//Letra A
void eliminaKEsimo(listaInt *l, int k){
	if(k == l->nElems){
		l->nElems--;
	}else if(k < l->nElems){
		int i;
		for(i=k; i < nElems; i++)
			l->chave[i] = l->chave[i+1];
		l->nElems--;
	}
}

//Letra B
void retiraMaior(listaInt *l){
	int i, maior, pos_maior;
	if(l->nElems){
		maior=l->chave[0];
		for(i=1; i < l->nElems; i++)
			if(l->chave > maior){
				maior = l->chave;
				pos_maior=i;
			}
		for(i=pos_maior; i < nElems-1; i++)
			l->chave[i] = l->chave[i+1];
	}
}

//Letra C
void retiraElementos(listaInt *l, int x){
	int i, j, cont=0;
	for(i=0; i < l->nElems; i++){
		if(l->chave == x){
			l->nElems--;
			for(j=i; j < l->nElems; j++)
				l->chave[j] = l->chave[j+1];
		}
	}
}