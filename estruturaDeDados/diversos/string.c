#include <stdio.h>
#include <string.h>
struct Nomes{
	char letra[51];
	int pos[51];
};
int main(){
	int i, n, j, q;
	scanf("%d", &n);
	struct Nomes nome[51];
	for (i = 0; i < n; ++i){
		scanf(" %[^\n]s", nome[i].letra);
		printf("%s\n", nome[i].letra);
		q=strlen(nome[i].letra);
		for (j = q-1; j >= 0; j--){
			if(nome[i].letra == ' ')
				nome[i].pos[]=j+1;
			printf("q:%d i:%d n:%d\n",q, i, n);
//			break;
		}
	}
	return 0;
}