#include<stdio.h>
int  abs( int x ){
      if( x < 0 ) 
        return -x;
      else
        return x;
    }
/*Funcao usada para retornar o modulo de um numero*/
main () {
	long int M[45000], N[45000];
	long int k, l, pc, j, i, b, n, m;
	scanf("%ld%ld",&n, &m);
	for (i=0; i<n; ++i)
		scanf("%ld", &N[i]);
	for (i=0; i<m; ++i)
		scanf("%ld", &M[i]);
/*Comandos acima para entrada de dados*/
	pc=0;
	k=0;
	l=0;
	b=0;
	for(j=0; j<m; ++j){
		for (i=0; i<n; ++i){
			if (N[i] == M[b]){
				k=i-l;
				l=i; 
				b++; 
				break; //Sai do for de dentro e vai pro for de fora
			}
		}
		pc=pc+abs(k);
	}
	printf("%ld\n",pc);
return 0;
}