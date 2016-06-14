#include<stdio.h>
#include<string.h>
int cont=0;
int verifica(char *numero){
	int soma=0, i, x;
	char buf[1001];
//	printf("%s\n", numero);
	x=strlen(numero);
	cont++;
	for (i = 0; i < x; i++){
		soma+=numero[i]-'0';
	}
	if (soma<=9)
		return 1;
	else{
		sprintf(buf, "%d", soma);
		char *test = strdup(buf);
//		return verifica(test)+1;
//		free(test);
		verifica(test)+1;
		return cont;
	}
} 
int main(){
	char valor[1001], saida='0';
	scanf("%s", valor);
	while(valor[0]!='0'){
		printf("%s is a multiple of 9 and has 9-degree %d.\n", valor ,verifica(valor));
		scanf("%s", valor);
	}
	return 0;
}

//-fno-builtin-strlen
// atoi(char *)


// 99999999999