#include <stdio.h>
int main(){
	int i, x[20],j=0;
	for (i = 0; i < 20; i++)
		scanf("%d", &x[i]);
	for(i = 19; i >= 0; i--)
		printf("N[%d] = %d\n", j++, x[i]);
	return 0;
}
