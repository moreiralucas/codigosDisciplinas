#include <stdio.h>
int main(){
	int a, b, k, x, i, cont=0;
	scanf("%d%d%d", &k, &a, &b);
	for (i = a; i <= b; i++){
		if((i%k)==0)
			cont++;
	}
	printf("%d\n",cont );
	return 0;
}