#include <stdio.h>
#include <string.h>
int main(){
	int dez=5, i=0, j, w, indice[100], maior=0;
	char alimento[101][50], sugestao[50];
	for (j = 0; j < 100; j++) indice[j]=0;
		
	while(1){

		w=0;
		printf("Digite a opcao do dia:\n");
		scanf("%s", sugestao);
		printf("\33[H\33[2J");  //Limpa a tela
		if(i==0){
			strcpy(alimento[i],sugestao);
			indice[i++]++;
		}else{
			for (j = 0; j < i; j++){
				if (strcmp(alimento[j],sugestao)==0){
					indice[j]++;
					w=1;
					break;
				}
			}
			if (w == 0){
				strcpy(alimento[i],sugestao);
				indice[i++]++;
			}
		}
		for (j = 0; j < i; j++){
			if(indice[j]>=maior){
				maior=indice[j];
				w=j;
			}
		}
		printf("A opcao do dia eh: %s\n\n",alimento[w]);
		//printf("******************\n%s votos(%d)w:%d\n\n",alimento[w], indice[w],w);
	}
	return 0;
}