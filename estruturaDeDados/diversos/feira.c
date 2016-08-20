#include <stdio.h>
typedef struct{
	char fruta[51];
	int preco;
}Feira;
int main(){
	int q, i, j, m, n, total;
	char aux[51];
	scanf("%d", &n);
	for (i = 0; i < n; ++i){
		scanf("%d", &m);
		Feira produto[m+1];
		for (j = 0; j < m; ++j)
			scanf("%s%d", produto[j].fruta, &produto[j].preco);
		for (j = 0; j < m; ++j){
			menor_i=j;
			for (q = j+1; q < m; ++q){
				if(strcmp(produto[q].fruta,produto[menor_i].fruta ) < 0)
					menor_i=q;
				strcpy(vetor[j],aux);
 				strcpy(vetor[menor_i],vetor[ j ]);
 				strcpy(aux,vetor[menor_i]);
			}
		}

		scanf("%d", &m);
		for (j = 0; j < m; ++j){
			scanf("%s%d", fruta, &qtd);
		}
	}
	return 0;
}