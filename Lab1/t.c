#include<stdio.h>
int main(){
	#define mil 1000
	int i, t, cont=0;
	scanf("%d", &t);
	while(cont<mil)
		for(i=0;i<t;i++){
			printf("N[%d] = %d\n", cont, i);
			cont++;
			if(cont==mil) break;
		}
	return 0 ;
}
