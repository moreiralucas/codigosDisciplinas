#include <stdio.h>
#include <string.h>
int main(){
	#define doze 12
	int i, j, l;
	float mat[doze][doze], soma=0.0;
	char letra;
//	mat[0][1]=555555.0;
	scanf("%d", &l);
//	printf("Valor de L:%d\n",l );
	scanf(" %c", &letra);
//	printf("Valor de letra:%c",letra );
	
	for (i = 0; i < doze; i++){
		for (j = 0; j < doze; j++){
			scanf("%f",&mat[i][j]);
//			mat[0][1]=555555.0;
//			printf("%f ", mat[i][j]);
		}
//		printf("\n");
	}
	for (i = 0; i < doze; i++)
		soma+=mat[i][l];
	if (letra=='M')
		soma/=doze;
	printf("%.1f\n",soma);
	return 0;
}