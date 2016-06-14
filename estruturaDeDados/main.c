#define <stdio.h>
int main(){
	Fila *fi;
	fi= cria_Fila(); //para criar a fila
	int x=insere_Fila(fi dados_aluno);
	libera_Fila(fi); //Para liberar a fila

	return 0;
}