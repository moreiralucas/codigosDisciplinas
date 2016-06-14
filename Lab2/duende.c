#include <stdio.h>
#include <stdlib.h>
#define maxtam 2001
//#define tamTeste 300
//static int fila[maxtam];
static matrix[maxtam][maxtam];
int cont=0;

typedef struct{
	int vetor[maxtam];
	int begin;
	int end;
}Fila;
Fila* filaConstrutor(){
	Fila* fila;
	fila=(Fila*) malloc(sizeof(Fila));
	if(fila != NULL)
		fila->vetor[0]=0;
	fila->end=1;
	fila->begin=0;
	return fila;
}
int filaVazia(Fila* fila){
	if(fila->end-1<=fila->begin)
		return 1;
	else
		return 0;
}
int filaCheia(Fila* fila){
	if(fila->begin==0 && fila->end==maxtam-1)
		return 1;
	else
		return 0;
}
int filaPush(int valor, Fila* fila){ // Push = Inserir
	if(filaCheia(fila))
		return 0;
	else{
		fila->vetor[fila->end-1]=valor;
		fila->end++; 
		return 1;
	}
}
int filaPop(Fila* fila){ // Pop = Desempilhar
	if(filaVazia(fila))
		return -1;
	else{
		fila->begin++;
		int c=fila->vetor[fila->begin-1];
		return c;
	}
}
int verificaRepetido(int valor, Fila* fila){
	int i;
	for (i = 0; i < fila->end; ++i)
		if (valor == fila->vetor[i])
			return 1;
	return 0;
}
void imprimeMatriz(int n, int m, int matrix[][maxtam]){
	int i, j;
	printf("---Matriz---\n   ");
	for (i = 1; i <= m; ++i) printf("%d ",i ); printf("\n   ");
	for (i = 1; i <= m; ++i) printf("__"); printf("\n");
	for (i = 1; i <= n; ++i){ //Matrix de N x N
		printf("%d |", i);
		for (j = 1; j <= m; j++){
			printf("%d ",matrix[i][j]);
		}
		printf("\n");
	}
	printf("----end-----\n");
}
int grafo(int w, int n, int matrix[][maxtam]){
	int i, q, cont=0;
	Fila* espera;
	Fila* visitados;
	espera = filaConstrutor(); 
	visitados = filaConstrutor();
	filaPush(w,espera); //s é a cordenada do último ponto visitado 
	filaPush(w,visitados);
	while(filaVazia(espera) == 0){
		int a=filaPop(espera); //o elemento da fila
		cont++;
		for (i = 1; i <= n; i++){ //printf("matrix[a][i]%d a:%d i:%d\n",matrix[a][i], a,i);
			if(matrix[a][i]==1)
				if(!verificaRepetido(i,espera)){
					filaPush(i,espera);// printf("Varrendo Matriz:%d\n",i);
					filaPush(i,visitados);
				}
		}
	}
	//if(cont != n)
	//	return 0;
	//else
		return 1;
}
int main(){
	int n/*intersecções*/, m/*numRuas*/, i, j, v, w, p;
//	scanf("%d %d", &n, &m);
	Fila* vertices;
//	vertices = filaConstrutor();
	scanf("%d%d", &n,&m);
	for (i = 1; i <= n; ++i){
		for (j = 1; j <= m; ++j){
			scanf("%d ", &matrix[i][j]);
		//	printf("%d ", matrix[i][j]);
		} //printf("\n");
	}
	imprimeMatriz(n,m,matrix);
	return 0;
		
}