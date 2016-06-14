#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#define D 16
int main (){
/*	int vetor=9;
	printf("sizeof vetor: %li\n", sizeof(vetor) );
	printf("int %d\n", (int)sizeof(vetor));

	short x = 10;
	int c[10];

	short *p = &x;

	printf("%d\n", clock() );*/
//	int *p = (int *)malloc(sizeof(int));
//	
//	int count=25, i, j, vetor[50];
//	for (i = 0; i < count; ++i){
//		scanf("%d", &vetor[i]);
//		printf("%d ", vetor[i]);
//	}
//	printf("\nDigite a posicao de i e de j:\n");
//	scanf("%d %d", &i, &j);
//	printf("%d\n",vetor[i*5+j]);
	int a=1, i;
	for (i = 1; i <= 10; ++i){
		a*=2;

	printf("%d\n", a);
	}
	return 0 ;
}