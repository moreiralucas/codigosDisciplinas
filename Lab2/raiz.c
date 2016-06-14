#include <stdio.h>
int main (){
	int n, i;
	scanf("%d", &n);
	float begin=0, end=n, meio;
//	while(begin<end){
	for (i = 0; i < 200; i++){
		meio=(begin+end)/2;
		if(meio*meio >= n)
			end=meio;
		else
			begin=meio;
	}
//	printf("A raiz de %d eh:%.3f\n", n, meio);	
	printf("%.3f\n", meio);
	return 0;
}