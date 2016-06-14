#include <stdio.h>
#include <string.h>
#define tam 1001
int verificaletras(char* senha, int n, int m, int a, int k){
	int M=0, A=0, K=0, i, z=strlen(senha);
	if(z<n)
		return 0;
	for (i = 0; i < z; ++i){ 
		if(senha[i] >= 65 && senha[i]<=90)
			A++; 
		if(senha[i] >= 97 && senha[i]<=122)
			M++; 
		if(senha[i] >= 48 && senha[i]<=57)
			K++; 
	}
	if(a<=A && m<=M && k<=K)
		return 1;
	return 0;
}
int main(){
	int i, j, n, m, a ,k;
	char senha[tam];
	scanf("%d%d%d%d %s", &n, &m, &a, &k, senha);
	printf("%s\n",senha );
	if (verificaletras(senha, n, m, a, k))
		printf("Ok =/\n");
	else
		printf("Ufa :)\n");
	return 0;

}