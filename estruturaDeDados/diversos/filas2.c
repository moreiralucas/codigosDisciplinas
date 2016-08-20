#include <stdio.h>
#include <string.h>
#define max 100
struct fila{
	int inicio, fial, qtd;
	struct aluno dados[MAX]
}
Fila* cria_Fila(){
	Fila *fi = (Fila*) malloc(sizeof(struct fila));
	if(fi = NULL){
		fi ->inicio =0;
		fi ->final =0;
		fi ->qtd =0;
	}
	return fi;
}
void liber_Fila(Fila* fi){
	free(fi);
}
int insere_Fila(Fila* fi, struct aluno al){
	if(fi == NULL) return 0;
	if(Fila_cheia(fi)) return 0;
	fi->dados[fi->final] = al;
	fi->final = (fi-final+1)%max;
	fi->qtd++;
}