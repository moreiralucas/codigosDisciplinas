#include <stdio.h>
int main(){
	int i, a, b, c;
	char url[]="1.txt";
	char letra;
	FILE *arquivo;
	arquivo = fopen(url, "r");
	if(arquivo == NULL)
			printf("Erro, nao foi possivel abrir o arquivo\n");
	else{
		for (i = 0; i < 10; i++){
		//while( (fgets(letra, sizeof(letra), arquivo))!=NULL ){
			fscanf(arquivo,"%c %d %d", &letra,&a, &b);
			printf("%c %d %d\n", letra,a, b);
		}
	}
	fclose(arquivo);
	return 0;
}
