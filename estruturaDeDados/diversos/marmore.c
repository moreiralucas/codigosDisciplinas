#include <stdio.h>
int compara(const void * a, const void * b){	//Funcao compara
	return (*(int*)a - *(int*)b);
}
int main (){
	int esq, dir, meio, n, q, i, j, c, CASE=1, result;
	scanf("%d%d", &n, &q);
	while(n != 0 && q != 0){

		int vet[n];
		for (i = 0; i < n; i++)
			scanf("%d", &vet[i]);
		printf("CASE# %d:\n", CASE++);
		qsort(vet, n, sizeof(int), compara);	//chama funcao compara(ordena)
		for (i = 0; i < q; i++){
			scanf("%d", &c);
			esq=0; dir=n-1;
			while(esq<=dir){			//Inicia a bsuca binaria
				meio=(esq + dir)/2;
				if (c < vet[meio])
					dir=meio-1;
				else
					if(c == vet[meio])
						break;
					else
						esq=meio+1;
			}
			if(c == vet[meio]){	//
				if(meio>0){		//if para verificar se o indice do numero encontrado eh maior q zero
					for (j = meio-1; j >=0 ; j--){ //Busca à esquerda um numero igual ao encontrado 
						if(vet[j]==c)	//verifica se o numero no vetor eh igual ao procurado
							result=j;
						else{
							result=j+1;
							break;
						}
					}
				}
				else{
					result=meio;
				}
				printf("%d found at %d\n", c, result+1);
			}else{
				printf("%d not found\n", c);

			}
		}
		scanf("%d%d", &n, &q);
	}
	return 0;
}