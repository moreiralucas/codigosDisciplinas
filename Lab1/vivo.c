#include<stdio.h>
#include<stdlib.h>
int main(){
	int i, j, p, l, r, n, J, a[10000],  contador=0;
	scanf("%d %d", &p, &r);
	while(p!= 0 && r!= 0){
		int x[p];
		for (i = 0; i < p; ++i){
			scanf("%d", &x[i]);
	//		printf("x[i]:%d\n", x[i]); //Imprimindo entrada
		}
	//	printf("\n");
		for (i = 0; i < r; i++){
			scanf("%d %d", &n, &J);
	//		printf("-------------------\nOutro Loop - n:%d J:%d", n, J); //Imprimindo entrada
			l=0;
	//		printf("\n");
			for (j = 0; j < n; j++){
				scanf("%d", &a[j]);
	//			printf("a[j]:%d", a[j]); //Imprimindo entrada
				if (a[j]==J){
					x[l]=x[j];
					
	//				printf("\nEntrou no IF\na[j]:%d x[l]:%d l:%d\n", a[j], x[l], l);
					l++;
				}
	//		printf("\n");	
			}
	//		printf("\n");
			for (j = 0; j < n; ++j){
				if (x[j]== -1){
					x[j]=x[j+1];
					j--;
				}
			}				 
		}
		printf("Teste %d\n%d\n\n", ++contador, x[0]);
		scanf("%d %d", &p, &r);
		system("cls");
	}
	return 0;
}