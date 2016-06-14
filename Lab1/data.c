#include<stdio.h>
#include<stdlib.h>
main (){

	printf("Data: %s Hora: %s\n", __DATE__,__TIME__);
	printf("\e[H\e[2J"); //Limpa a tela
	printf("Apagou\n");
	return 0;
}