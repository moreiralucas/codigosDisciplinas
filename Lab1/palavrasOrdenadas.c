#include <stdio.h>
#include <string.h>
int main(){
	int j, i, n, cont;
	char palavra[43], palavra2[43];
	scanf("%d", &n);
	for (i = 0; i < n; ++i){
		scanf(" %s", palavra);
		strcpy(palavra2,palavra);
		j=0;
		cont=1;
		if(palavra2[0]>='A' && palavra2[0]<='Z')
			palavra2[j]+=32;
		while(palavra2[j+1] != '\0'){
			if(palavra2[j+1]>='A' && palavra2[j+1]<='Z')
 					palavra2[j+1]+=32;
 				if(palavra2[j]<palavra2[j+1])
 					cont++;
 			j++;
		}
		if (cont == strlen(palavra))
			printf("%s: O\n",palavra);
		else
			printf("%s: N\n",palavra);
	}
	return 0;
}