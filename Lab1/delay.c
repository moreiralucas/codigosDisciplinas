#include <stdio.h>
#include <time.h>
//#include <dos.h>
#include <stdlib.h>

int main()
{
int i, del, x; // A duração do delay
printf("Digite o tempo de delay (em segundos): ");
scanf("%i",&del); 
del *= 1000; // Multiplique por 1000 para converter o tempo em milissegundos
//delay(del); // Delay.
for(;;){
	for (i = 0; i < 10; ++i){
		sleep(1);
		x=rand() % 2;
		printf("%d ", x);
		fflush(stdout);
	}
}
printf("Pronto.");
return 0;
}