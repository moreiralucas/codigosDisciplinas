#include <stdio.h>
#include <string.h>
int custo;
int minimo(int a/*Superior*/, int b/*Esquerda*/, int c/*Diagonal esquerda*/){
	a++;
	b++;
	c+=custo;
	int menor=a;
	if(b<=menor) menor=b;
	if(c<=menor) menor=c;
	return menor;
}
int main(){
	int menor, p, j, n, i, tamA, tamB;
	static int matrix[2001][2001];
	char a[2001], b[2001];
	scanf("%d", &n); //Quantidade de casos de testes
	for(p=0;p<n;p++){ //Casos de teste i
//		printf("\nCaso de Teste: %d\n",p+1 );
		scanf("%s",a);
		scanf("%s",b);
		tamA=strlen(a)+1; //printf("Valor de tamA: %d\n", tamA);
		tamB=strlen(b)+1; //printf("Valor de tamB: %d\n", tamB);
		printf("%s\n%s\n", a,b);
		for(i=0;i<tamA; i++)
			if(i<tamA) matrix[0][i]=i; //Inicializando a primeira linha da matriz
		for(i=0;i<tamB; i++)
			if(i<tamB) matrix[i][0]=i; //Inicializando a primeira coluna da matriz
		
		for(i=1;i<tamB;i++){
			for(j=1;j<tamA;j++){
				if(a[j-1]==b[i-1])
					custo=0;
				else
					custo=1;
				matrix[i][j]=minimo(matrix[i-1][j], matrix[i][j-1], matrix[i-1][j-1]);
//				printf("Minimo:%d\n",matrix[i][j]);
			}

		}
//		matrix[7][8]=9;
/*		printf("  *");
		for(i=0;i<tamA;i++)
			printf(" %c",a[i]);
		printf("\n");
		for(i=0;i<tamB;i++){
			if(i>0) printf("%c ", b[i-1]);
			else printf("* ");
			for(j=0;j<tamA;j++){
				printf("%d ",matrix[i][j]);
			}
			printf("\n");
		}
		printf("%d\n",matrix[i-1][j-1]);
*/	}

	return 0;
}