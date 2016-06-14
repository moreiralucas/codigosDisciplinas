#include <stdio.h>
#include <string.h>
int main(){
	#define doze 12
	int i, j, l=1, cont=0, x;
	float mat[doze][doze], soma=0.0;
	char letra;
	scanf(" %c", &letra);
	
	for (i = 0; i < doze; i++){
		for (j = 0; j < doze; j++){
			scanf("%f",&mat[i][j]);
		}
	}
	x=doze;
	for (i = 1; i < doze-1; i++){
		
		if (i<6)
			x--;
		else if(i==6)
			x=7;
		else
			x++;
//		printf("Valor de X%d -i:%d\n",x,i);
		for (j = x; j < doze; j++){
			soma+=mat[i][j];
//			mat[i][j]=0.0;
			cont++;

		}

//		l++;
	}

//	for (i = 0; i < doze; i++){
//		for (j = 0; j < doze; j++)
//			printf("%1.f ", mat[i][j]);
//		printf("\n");
//	}	
	if (letra=='M')
		soma/=cont;
	printf("%.1f\n",soma);
	return 0;
}