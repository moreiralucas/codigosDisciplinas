#include<stdio.h>
int main(){
	int i, n, menor, posicao=0;
	scanf("%d", &n);
	int vet[n];
	scanf("%d", &vet[0]);
	menor=vet[0];
	for(i=1; i<n;i++){
		scanf("%d", &vet[i]);
		if(vet[i]<menor){
			menor=vet[i];
			posicao=i;
		}
	}
	printf("Menor valor: %d\n", menor);
	printf("Posicao: %d\n", posicao);
	return 0 ;
}
