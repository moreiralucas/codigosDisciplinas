#include <stdio.h>
int k, cont=0;
int acoes(int n){
	if(n>k){
		if(n%2){//par
			int a=n/2;
			acoes(a);
			acoes(a);
			cont=+2;
			//cont++;
			printf("Cont1:%d\n",cont);
		}else{ //impar
			int a=n%2;
			acoes(a);
			a=n/2;
			acoes(a);
			cont+=2;
			//cont++;
			printf("Cont2:%d\n",cont);
		}
	}
	return cont;
}
int main(){
	int n;
	while(scanf("%d %d", &n, &k),n,k){
//		printf("Acoes:%d\n", acoes(n));
//		cont=0;
		acoes(n);
		printf("Result:%d\n",cont);
		break;
	}
//printf("4 mod 2:%d\n", 4%2);
//printf("4/2:%d\n",4/2);
	return 0;
}
