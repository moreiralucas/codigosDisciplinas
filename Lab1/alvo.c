#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main () {
	long long int c, i, p, t, x, y, meio, esq, dir, valor;
	long long int raio, pontos=0;

	scanf("%lld %lld", &c, &t);
	long long int r[c];
	for(i=0; i<c; i++){
		scanf("%lld", &r[i]);
		r[i]=r[i]*r[i];
	}
	for(i=0; i<t; i++){

		scanf("%lld %lld", &x, &y);		
		raio=pow(x,2) + pow(y,2);

			esq=0;
			dir=c-1;
			while(esq < dir) {
				meio = (esq + dir)/2;
				if(raio <= r[meio])
					dir=meio;
				else
					esq = meio+1;
			}
		if(raio>r[c-1])
			pontos+=0;
		else
			pontos+=c-dir;
	}
	printf("%lld\n", pontos);
	return 0;
}