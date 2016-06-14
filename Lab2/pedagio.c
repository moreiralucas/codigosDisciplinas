#include <stdio.h>
#include <stdlib.h>
#define maxtam 51
static matrix[maxtam][maxtam];
int cont=0;
int vetor[51];
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
//void imprimeMatriz(int n, int matrix[][maxtam]){
//	int i, j;
//	printf("---Matriz---\n   ");
//	for (i = 1; i <= n; ++i) printf("%d ",i ); printf("\n   ");
//	for (i = 1; i <= n; ++i) printf("__"); printf("\n");
//	for (i = 1; i <= n; ++i){ //Matrix de N x N
//		printf("%d |", i);
//		for (j = 1; j <= n; j++){
//			printf("%d ",matrix[i][j]);
//		}
//		printf("\n");
//	}
//	printf("----end-----\n");
//}
int pedagio(int p/*Número máximo*/,int w/*Nó inicial*/, int n/*Tamanho da matriz*/, int matrix[][maxtam]){
	int i, q, cont=0,z=0;
	for(i=1;i<=50;i++){ vetor[i]=0;}
	Fila* espera;
	Fila* visitados;
	espera = filaConstrutor(); 
	visitados = filaConstrutor();
	filaPush(w,espera); //w é a cordenada do último ponto visitado 
	filaPush(w,visitados);
	while(filaVazia(espera) == 0){ 
		int a=filaPop(espera); //o elemento da fila
		//cont++; //printf("a:%d cont:%d\n",a,cont );
		for (i = 1; i <= n; i++){ //printf("matrix[a][i]%d a:%d i:%d\n",matrix[a][i], a,i);
			if(matrix[a][i]==1){ //printf("z:%d\n",z++);
				if(!verificaRepetido(i,espera)){
					filaPush(i,espera);// printf("Varrendo Matriz:%d\n",i);
					filaPush(i,visitados);
					vetor[i]=vetor[a]+1;
					cont++;
					if(vetor[i]>p) return cont;
				}
			}
		}// imprimeMatriz(n,matrix);
	}
	return 0;
}
int main(){
	int i, c, e, l, p, x, y, j, test=1;
	while(scanf("%d%d%d%d", &c, &e, &l, &p),c,e,l,p){
		printf("Teste %d\n", test++);
		for (i = 1; i <= c; ++i){
			for(j=1;j<=c;j++){
				matrix[i][j]=0;
			}
		} //imprimeMatriz(c,matrix);
		for (i = 0; i < e; ++i){
			scanf("%d%d", &x, &y);
			matrix[x][y]=1;
			matrix[y][x]=1;
		}// printf("C:%d E:%d L:%d P:%d\n", c, e, l, p);
		int n=pedagio(p,l,c,matrix); //printf("\n");
		for(i=0;i<51;i++) if(vetor[i]>0 && vetor[i]<=p)	printf("%d ", i);
		printf("\n\n");
//		imprimeMatriz(c,matrix);
	}
	return 0;
}