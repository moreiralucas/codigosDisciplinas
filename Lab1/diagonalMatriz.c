#include <stdio.h>
#include <string.h>
int main(){
	#define doze 12
	int i, j, l=1, cont=0;
	float mat[doze][doze], soma=0.0;
	char letra;
	scanf(" %c", &letra);
	
	for (i = 0; i < doze; i++){
		for (j = 0; j < doze; j++){
			scanf("%f",&mat[i][j]);
			printf("%1.f ", mat[i][j]);
		}
		printf("\n");
	}
	for (i = 1; i < doze; i++){
		for (j = 0; j < l; j++){
			soma+=mat[i][j];
			cont++;
		}
		l++;
	}
	if (letra=='M')
		soma/=cont;
	printf("%.1f\n",soma);
	return 0;
}