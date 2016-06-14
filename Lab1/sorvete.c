#include <stdio.h>
int main (){
	int vet[10002], s, p, i, j, u, v, inicio, teste=0;
	scanf("%d %d", &p, &s);
	while(s != 0 && p!= 0){
		printf("Teste %d\n", ++teste);
		inicio=0;
//		fim=0;
		for (i = 0; i <= p+1; i++){
			vet[i]=0;
//			printf("Zerou o vetor %d\n", i);
		}
		for (j = 0; j < s; j++){
			scanf("%d %d", &u, &v);
//			printf("Leu U e V\n");
			for (i = u; i <= v; i++){
				vet[i]=1;
//				printf("incrementou local do sorveteiro\n");
			}
		}
//		printf("Vet[i]:%d\n",vet[0]);
		for (i = 0; i <= p; i++){
//			printf("Vetor[%d]:%d \n", i,vet[i]);
			if(vet[i] == 1 && inicio == 0){
				inicio=i;
//				printf("Localizou um Inicio\n");
			}
			if(inicio != 0 && vet[i+1] == 0){
				printf("%d %d\n", inicio, i);
				inicio=0;
			}
		}
		printf("\n");
		scanf("%d %d", &p, &s);
	}

	return 0;
}