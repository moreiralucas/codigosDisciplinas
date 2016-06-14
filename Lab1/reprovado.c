#include<stdio.h>
#include<string.h>
int main(){
	int aux, n=10, i, j, pontos[100], menor_i, inst=0;
	char nomeAux[101], nome[101][101];
/*	for (i = 0; i < n; ++i)
	{
		scanf("%d", &pontos[i]);
	}
*/	
//	scanf("%d", &n);
	while(scanf("%d", &n)!= EOF){
		for (i = 0; i < n; ++i){
			scanf("%s%d", nome[i], &pontos[i]);
		}
//		printf("Entrada(desordenada)\n");
//		for (i = 0; i < n; ++i){
//			printf("%s %d\n", nome[i], pontos[i]);
//		} 
		for (j = 0; j < n-1; j++){
			menor_i=j;
			for (i = j+1; i < n; i++)
				if (pontos[i] > pontos[menor_i] || (pontos[i] == pontos[menor_i] && ((strcmp(nome[i],nome[menor_i])) < 0))) // strcmp(string1, string2)
					menor_i=i;
			aux=pontos[j];
			strcpy(nomeAux,nome[j]);
//			printf("NomeAux: %s\n", nomeAux);

			pontos[j]=pontos[menor_i];
			strcpy(nome[j],nome[menor_i]);

			pontos[menor_i]=aux;
			strcpy(nome[menor_i],nomeAux);
			
//		} printf("-----------\nOrdenado\n-----------\n");
			
//			printf("%s\n",xx );
	
		}	
//		for (i = 0; i < n; ++i){
//			printf("%s %d\n", nome[i], pontos[i]);
//			printf("%d\n", pontos[i]);
		printf("Instancia %d\n%s\n\n", ++inst, nome[n-1]);
	}
	return 0;
}
//		Possíveis valores de retorno:
//		0: conteúdo das strings são iguais
//		< 0: conteúdo da string1 é menor do que string2
//		> 0: conteúdo da string1 é maior do que string2