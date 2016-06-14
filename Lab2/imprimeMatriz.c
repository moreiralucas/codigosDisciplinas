#include <stdio.h>
#define tam 700
void imprimeMatriz(int matrix[][tam], int n){
	int i, j;
	for (i = 1; i <= n; i++){ //Matrix de N x N
		for (j = 1; j <= n; j++){
			printf("%d ",matrix[i][j]);
		}
		printf("\n");
	}
}
int main(){
	int n, matrix[tam][tam];
	printf("Digite o tamanhoa da dimensão N x N:\n");
	scanf("%d", &n);
	imprimeMatriz(matrix, n);
	return 0;
}