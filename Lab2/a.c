#include<stdio.h>
#define max 2000
int begin=1, end=2, matrix[max][max], s[max]/*conjunto S*/, T[max]/*Posicoes vizitadas*/;
void imprimeMatriz(int n, int matrix[max][max]){
	int i, j;
	for(i=1; i<=n; i++){
		for(j=1; j<=n; j++)
			printf("%d ", matrix[i][j]);
		printf("\n");
	}
}
int verificaS(int n,int s[max]){ //verifica se o conjunto S eh vazio
	int i;
	for(i=0;i<n;i++)
		if(s[i]!=0)
			return 1;
	return 0;
}
int insere(int s[max], int end, int j){
	int i;
	for(i=0; i<=end; i++)
		if(s[i]==j)
			return 0;
		return 1;			
}	
int main(){
	int m, n, i, j, v, w, p, vi;
	scanf("%d%d", &n, &m);
	for(i=1; i<=n; i++){ 
		for(j=1; j<=n; j++)
			matrix[i][j]=0; //Zerando toda a matriz
		s[i]=0;	//Zerando o conjunto S
		T[i]=0;	//Zerando o vetor T
	}
	for(i=1; i<=m; i++){
		scanf("%d%d%d", &v, &w, &p);
		matrix[v][w]=1;
		if(p==2)
			matrix[w][v]=1;
	}
	int a=3;
	int indiceT=1;
	imprimeMatriz(n, matrix);
	s[1]=1;
	while(verificaS(n,s)){
		vi=s[begin];
		s[begin++]=0;
		T[indiceT++]=vi;
//		for(i=1; i<=n; i++){ 
		for(j=1; j<=n; j++)
			if(matrix[vi][j]){
				if(insere(s, end, matrix[vi][j]))
					s[end++]=matrix[vi][j];
			}
		printf("T[j]:");
		for(j=1; j<=n; j++)
			printf("%d ",T[j]);
		printf("\n\ns[j]");
		for(j=1; j<=10; j++)
			printf("%d ", s[j]);
		printf("\n\n\n");
		if(!a--)
			break;
	}
	return 0;
}
