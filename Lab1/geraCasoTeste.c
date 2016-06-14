#include <stdio.h>
int main (){
	int cont=0,a=0,b=0,i;
	printf("50 100\n");
	for(i=2;i<=100;i+=2){
		printf("%d ", i);
		cont++;
	}
	printf("\n");
	a=cont;
	cont=0;
	for(i=100; i>=30;i-=2){
		printf("%d ",i);
		cont++;
	}
	for(i=50;i>=2;i-=2){
		printf("%d ",i);
		cont++;
	}
	printf("\n");
	for(i=4;i<=80;i+=2){
		printf("%d ",i);
		cont++;
	}
	printf("\n");
	b=cont;
//	printf("a:%d b:%d\n", a,b);
return 0;
}
