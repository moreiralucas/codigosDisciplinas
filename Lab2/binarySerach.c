#include<stdio.h>
#include<stdlib.h>
int compara(const void * a, const void * b){	//Funcao compara
	return (*(int*)a - *(int*)b);
}
int main(){
	int j, n, i, q, numero, esq, dir, meio, result;	//Entrada
	scanf("%d %d", &n,&q);
	int p[n];
	for ( i = 0; i < n; i++){
		scanf("%d", &p[i]);
	}
	qsort(p, n, sizeof(int), compara);	//chama funcao compara(ordena)
	for(j=0; j<q;j++){
		scanf("%d", &numero);
		esq=0; dir=n-1;
		while(esq<=dir){			//Inicia a bsuca binaria
			meio=(esq + dir)/2;
			if (numero < p[meio])
				dir=meio-1;
			else
				if(numero == p[meio])
					break;
				else
					esq=meio+1;
		}
		if(p[meio] == numero){	//
			if(meio>0){		//if para verificar se o indice do numero encontrado eh maior q zero
				for (i = meio-1; i >=0 ; i--){ //Busca à esquerda um numero igual ao encontrado 
					if(p[i]==numero)	//verifica se o numero no vetor eh igual ao procurado
						result=i;
					else{
						result=i+1;
						break;
					}
				}
			}
			else{
				result=meio;
			}
			printf("%d\n", result);
		}
		else{
			printf("-1\n");
		}
	}
	return 0;
}