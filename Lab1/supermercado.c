#include <stdio.h>
int compara(const void * a, const void * b){	//Funcao compara
	return (*(int*)a - *(int*)b);
}
int main(){
	float aux;
	int x[1001], y[1001], s, i, a, b;

	scanf("%d", &s);
	while(s){
		for (i = 0; i < s; i++)
			scanf("%d%d", &x[i], &y[i]);
		qsort(x, s, sizeof(int), compara);
		qsort(y, s, sizeof(int), compara);
		for (i = 0; i < s; i++)
			printf("x[%d]:%d |\\*/| y[%d]:%d\n",i, x[i], i, y[i]);
		s/=2;
		if(s%2==0){
//			s=s/2;
			a=(x[s]+x[s+1])/2;
			b=(y[s]+y[s+1])/2;
		}
		else{
//			s=(s/2);
			a=x[s+1];
			b=y[s+1];
		}
		printf("a:%d b:%d\n\n", a, b);
		scanf("%d", &s);
	}
	return 0;
}