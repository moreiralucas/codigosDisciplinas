#include <stdio.h>
int main (){
	int t, m, i, j, k, cont;
	char musica[3], trecho[3];
	scanf("%d %d", &m, &t);
	while(m){
		int S[t+1], S2[m+1], v[t+1];
		for (i = 0; i < m; i++){
			scanf("%s", musica); //S2
			if(musica[0] == 'A' && musica[1] == '\0') S2[i]=1;
			if(musica[0] == 'A' && musica[1] == '#') S2[i]=2;
			if(musica[0] == 'B' && musica[1] == 'b') S2[i]=2;
			if(musica[0] == 'B' && musica[1] == '\0') S2[i]=3;
			if(musica[0] == 'C' && musica[1] == 'b') S2[i]=3;
			if(musica[0] == 'C' && musica[1] == '\0') S2[i]=4;
			if(musica[0] == 'B' && musica[1] == '#') S2[i]=4;
			if(musica[0] == 'C' && musica[1] == '#') S2[i]=5;
			if(musica[0] == 'D' && musica[1] == 'b') S2[i]=5;
			if(musica[0] == 'D' && musica[1] == '\0') S2[i]=6;
			if(musica[0] == 'D' && musica[1] == '#') S2[i]=7;
			if(musica[0] == 'E' && musica[1] == 'b') S2[i]=7;
			if(musica[0] == 'E' && musica[1] == '\0') S2[i]=8;
			if(musica[0] == 'F' && musica[1] == 'b') S2[i]=8;
			if(musica[0] == 'F' && musica[1] == '\0') S2[i]=9;
			if(musica[0] == 'E' && musica[1] == '#') S2[i]=9;
			if(musica[0] == 'F' && musica[1] == '#') S2[i]=10;
			if(musica[0] == 'G' && musica[1] == 'b') S2[i]=10;
			if(musica[0] == 'G' && musica[1] == '\0') S2[i]=11;
			if(musica[0] == 'G' && musica[1] == '#') S2[i]=12;
			if(musica[0] == 'A' && musica[1] == 'b') S2[i]=12;
		} 
		for (i = 0; i < t; i++){
			scanf("%s", trecho); //S
			if(trecho[0] == 'A' && trecho[1] == '\0') S[i]=1;
			if(trecho[0] == 'A' && trecho[1] == '#') S[i]=2;
			if(trecho[0] == 'B' && trecho[1] == 'b') S[i]=2;
			if(trecho[0] == 'B' && trecho[1] == '\0') S[i]=3;
			if(trecho[0] == 'C' && trecho[1] == 'b') S[i]=3;
			if(trecho[0] == 'C' && trecho[1] == '\0') S[i]=4;
			if(trecho[0] == 'B' && trecho[1] == '#') S[i]=4;
			if(trecho[0] == 'C' && trecho[1] == '#') S[i]=5;
			if(trecho[0] == 'D' && trecho[1] == 'b') S[i]=5;
			if(trecho[0] == 'D' && trecho[1] == '\0') S[i]=6;
			if(trecho[0] == 'D' && trecho[1] == '#') S[i]=7;
			if(trecho[0] == 'E' && trecho[1] == 'b') S[i]=7;
			if(trecho[0] == 'E' && trecho[1] == '\0') S[i]=8;
			if(trecho[0] == 'F' && trecho[1] == 'b') S[i]=8;
			if(trecho[0] == 'F' && trecho[1] == '\0') S[i]=9;
			if(trecho[0] == 'E' && trecho[1] == '#') S[i]=9;
			if(trecho[0] == 'F' && trecho[1] == '#') S[i]=10;
			if(trecho[0] == 'G' && trecho[1] == 'b') S[i]=10;
			if(trecho[0] == 'G' && trecho[1] == '\0') S[i]=11;
			if(trecho[0] == 'G' && trecho[1] == '#') S[i]=12;
			if(trecho[0] == 'A' && trecho[1] == 'b') S[i]=12;
		}
		v[0]=0;
		k=0;
		for (i=1;i<t;i++){ 
			while (k>0 && S[i]!=S[k]){
				k=v[k-1];}
			if (S[i]==S[k]){
				/*v[i]=*/k++;
	//			v[i]=k++;
			}
			v[i]=k;
		}
		cont=0;
		j=0; 
		i=0; //printf("Posicação:\n"); int q; printf("%s\n%s\n",S,S2);
		while(j<m){
			j++;
			while(i>0 && S[i] != S2[j])
				i=v[i-1];
			if(S[i]==S2[j])
				i++;
			if(i == t){
				i=v[i-1];
				cont++;
			}
		}
		if (cont) printf("S\n");
		else printf("N\n");
		//printf("Total de substrings encontradas:%d\n",cont );
		scanf("%d %d", &m, &t);
	}
	return 0;
}
