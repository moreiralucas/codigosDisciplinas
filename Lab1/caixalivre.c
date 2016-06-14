#include <stdio.h>
int main (){
	int n, i, h, m, a=-1, b=-1, cont=0, max=0;
	scanf("%d", &n);
	for ( i = 0; i < n; i++){
		a=h; b=m;
		scanf("%d%d", &h, &m);
		if(a == h && b == m)
			cont++;
		else{
			if(cont > max)
				max=cont;
			cont=0;
		}
	}
			if(cont > max)
				max=cont;
	printf("%d\n",max+1 );
	return 0;
}