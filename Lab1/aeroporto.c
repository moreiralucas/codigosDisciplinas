#include<stdio.h>
int main (){
	long int a, b, n=1, i, v, x, y, vet[50000];

	scanf("%ld%ld",&a,&v); /*Entrada de dados*/

	while((v!=0)&&(a!=0)){	/*Entrada de dados e contabilização*/
		b=0;

		for(i=0; i<50000; i++) /*Zerando o vetor*/
			vet[i]=0;
		
		for(i=0;i<v;i++){
			scanf("%ld%ld",&x,&y);
			vet[x]++;
			vet[y]++;
		}
	
	for(i=0;i<=a;i++)
		if(vet[i]>b)
			b=vet[i];

	printf("Teste %ld\n", n++);
	
	for(i=0; i<=a; i++)
		if(b==vet[i]){
			printf("%ld ",i);
		}
	printf("\n\n");
	scanf("%ld%ld",&a,&v);
	}

return 0;
}
