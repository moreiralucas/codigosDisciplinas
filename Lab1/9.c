#include <stdio.h>
#include <string.h>
int cont, flag;
int verifica(int valor){
//	printf("Valor:%d cont:%d\n",valor, cont );
	int i, somatorio=0;
	
	while(valor > 9){
		somatorio+=valor%10;
		valor=valor/10;
//		printf("valor de 9 dentro do while %d  cont: %d\n", valor, cont);
	}
	if (somatorio <= 9){
		if(somatorio == 9)
			return 1;
		else
			return 0;
	}else{
		verifica(valor);
		cont++;
	}
}
int main(){
	int x, i, numero;
	char nove[1001];
	scanf("%s", nove);
	while(nove[0] !='0'){
		flag=0;
		cont=1;
		x=strlen(nove);
		numero=0;
		for (i = 0; i < x; ++i){
			numero+=nove[i]-48;
		}
		x=verifica(numero);
		if (x == 1)
			printf("%s is a multiple of 9 and has 9-degree %d.\n", nove, x);
		else if(x < 9)
				printf("%s is not a multiple of 9.\n", nove);
//			else
//				printf("%s is not a multiple of 9.\n", nove);
		
		scanf("%s", nove);
	}

	return 0;
}