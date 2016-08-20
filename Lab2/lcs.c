#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main (){
    int q, i, j, tam1, tam2, teste=0, matrix[101][101];
    char s1[101], s2[101],s3[101]={'L','u','c','a','s'};
	scanf("%s%s", s1, s2);
//    while(s1 != "#"){
		q=0;
    	tam1=strlen(s1)+1;
		tam2=strlen(s2)+1;
		for(i=0;i<tam1;i++)  // Zera a linha da Matriz
			matrix[0][i]=0;
		for(i=0;i<tam2;i++) // Zera a coluna da Matriz
			matrix[i][0]=0;

//		Atribui valores na Matriz
    	for(i=1;i<tam2;i++){
	    	for(j=1;j<tam1;j++){
				if(s1[j-1] == s2[i-1]){
					matrix[i][j]=matrix[i-1][j-1]+1;
				}else{
					if(matrix[i-1][j]>matrix[i][j-1])
						matrix[i][j]=matrix[i-1][j];
					else
						matrix[i][j]=matrix[i][j-1];
				}
			}
		}

    	printf("%d\n", matrix[tam2-1][tam1-1]);		
//    	printf("Matrix: %d\ntam1:%d tam2:%d\n", matrix[tam2-1][tam1-1], tam1-1, tam2-1);
//		scanf("%s%s", s1, s2);
//	}
    return 0;
}