#include <stdio.h>
int main (){
	int s, m, n, i, j;
	int memoria[50002];
	// 50002 equivale ao infinito, nesse algoritmo.
	scanf("%d%d",&m, &n);
	while(m){
		int moedas[n+1];
		for(i=0;i<n;i++)
			scanf("%d", &moedas[i]);
		for(i=1;i<=m;i++)
			memoria[i]=50001;
		memoria[0]=0;
		for(i=0;i<n;i++) //"for" da quantidade de moedas
			for(j=0;j<m;j++)
				if(memoria[j] != 50001 && j+moedas[i]<=m)
					if(memoria[j+moedas[i]]>memoria[j]+1)
						memoria[j+moedas[i]]=memoria[j]+1;
		if(memoria[m]<50001)
			printf("%d\n",memoria[m]);
		else
			printf("Impossivel\n");
		scanf("%d%d",&m, &n);
	}
	return 0;
}