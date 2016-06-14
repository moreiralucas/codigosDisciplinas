#include <stdio.h>
#include <string.h>
int main (){
    int q, i, j, tam1, tam2, teste=0, matrix[101][101];
    char s1[101], s2[101],s3[101]={'S','3'};
	
//	printf("%s\n%s\n", s1, s2); //Imprimindo entrada
//	printf("s1[0]:%c s2[0]:%c\n", s1[0], s2[0]);
    scanf("%s%s", s1, s2);
    while(s1[0] != '#'){
		q=0;
    	tam1=strlen(s1)+1;
		tam2=strlen(s2)+1;
		for(i=0;i<tam1;i++)  // Zera a linha da Matriz
			matrix[i][0]=i;
		for(i=0;i<tam2;i++) // Zera a coluna da Matriz
			matrix[0][i]=i;

//		Atribui valores na Matriz
    	for(i=1;i<tam1;i++){
	    	for(j=1;j<tam2;j++){
				if(s1[i] == s2[j]){
					matrix[i][j]=matrix[i-1][j-1]+1;
				}else{
					if(matrix[i-1][j] < matrix[i][j-1])
						matrix[i][j]=matrix[i-1][j]+1;
					else
						matrix[i][j]=matrix[i][j-1]+1;
				}
			}
		}
//		printf("tam1:%d tam2:%d\n", tam1, tam2);
//		printf("i:%d j:%d Inicial\n", i, j);
/*	// Imprime a Matriz
 * 		printf("  *");
 *		for(i=0;i<tam1;i++)
 *			printf(" %c",s1[i]);
 *		printf("\n");
 *		for(i=0;i<tam2;i++){
 *			if(i>0) printf("%c ", s2[i-1]);
 *			else printf("* ");
 *			for(j=0;j<tam1;j++){
 *				printf("%d ",matrix[i][j]);
 *			}
 *			printf("\n");
 *		}
 */		//printf("tam1: %d i: %d tam2: %d j: %d \n",tam1, i, tam2, j);
 		i--; j--;// Aqui eh decrementado os valores de I e J para se igualar ao tamanho real da string
		q=matrix[i][j];
		s3[q--]='\0'; 
//		printf("i:%d j:%d Inicial\n", i, j);
//************************
//		Back Track		//
//************************
		do{
//		printf("Entrou no While\n");
//			printf("i:%d j:%d\n", i, j);
			if(s1[j] == s2[i]  && i > 0 && j > 0 /*matrix[i][j] > matrix[i-1][j] && matrix[i][j] > matrix[i][j-1] */){
				s3[q]=s1[i];
//				printf("s1[j]:%c\n", s1[j]);
				i--; j--;
				//if(i <= 0) i=0;
				//if(j <= 0) j=0;
//				printf("Valor de q:%d Letra: %c '\\'\n", q-1,s3[q-1]); /// Debug
			}else{
				if(j > 0 && matrix[i][j]-1 == matrix[i][j-1]){
//					printf("s2[i]:%c\n", s2[i]);
					s3[q]=s2[j];
					j--;
//					printf("Valor de q:%d Letra: %c '|'\n", q-1,s3[q-1]); /// Debug
				}else{
//					printf("s1[i]:%c\n", s1[i]);
					s3[q]=s1[i];
					i--;
//					printf("Valor de q:%d Letra: %c '--'\n", q-1,s3[q-1]); /// Debug
				}
			}
//			printf("i:%d j:%d\n", i, j);
		}while(q-- > 0 /* && j>0*/);
//		Imprime a Matriz
//		printf("  *");
//		for(i=0;i<tam1;i++)
//			printf(" %c",s1[i]);
//		printf("\n");
//		for(i=0;i<tam2;i++){
//			if(i>0) printf("%c ", s2[i-1]);
//			else printf("* ");
//			for(j=0;j<tam1;j++){
//				printf("%d ",matrix[i][j]);
//			}
//			printf("\n");
//		}

    	printf("Teste %d\n", ++teste);
//		scanf("%s%s", s1, s2);


//    	for (i = 0; i > q; i++)
//    		printf("%c",s3[i]);
//    	printf("\n");
    	printf("%s\n", s3);
		printf("\n");    	
		scanf("%s%s", s1, s2);
	}

    return 0;
}