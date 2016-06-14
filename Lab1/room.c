#include <stdio.h>
int main (){
	int i, cont=0, n, p, q;
	scanf("%d", &n);
	for (i = 0; i < n; i++){
		scanf("%d %d", &p, &q);
		if(q-p >= 2)
			cont++;
	}
	printf("%d\n", cont);
}