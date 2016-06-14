#include <stdio.h>
#include <string.h>
int main (){
	int n, i,j,k, cont=0;
	
	while(scanf("%d", &n) != EOF){
		char S[n+1], S2;
		scanf("%s ",S);
		int v[n+1];
		v[0]=0;
		k=0;
		for (i=1;i<n;i++){
			while (k>0 && S[i]!=S[k])
				k=v[k-1];
			if (S[i]==S[k]){
				k++;
			}
			v[i]=k;
		}
		j=0;
		i=0; 
		int imprimiu = 0;
		scanf("%c", &S2);
		while(S2 != '\n'){
			j++;
			while(i>0 && S[i] != S2)
				i=v[i-1];
			if(S[i]==S2)
				i++;
			if(i == n){
				imprimiu = 1;
				printf("%d\n", j-i);
				i=v[i-1];
				cont++;
			}
			scanf("%c", &S2);
		}
		if (imprimiu) puts(""); //Equivalente ao printf("\n");
	}
	return 0;
}
