#include <stdio.h>
int main(){
	float a, b=0.0;
	int i;
	char url[]="arquivoTeste.txt";

	FILE *arquivo;
	arquivo = fopen(url, "wb");
	if(arquivo == NULL)
			printf("Erro, nao foi possivel abrir o arquivo\n");
	else{
		for (i = 0; i < 3; i++){
			printf("Digite a nota %d:\n",i+1);
			scanf("%f", &a);
			fprintf(arquivo, "Disciplina %d: %2.f\n", i+1, a);
			b+=a;
		}
		b/=3;
		fprintf(arquivo, "Media final: %.2f\n",b);
	}
	fclose(arquivo);
	return 0;
}
