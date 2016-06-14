#include <stdio.h>
int main(){
	int x, y, a, b, c, d, res=0; 
	scanf("%d%d%d%d%d%d", &x, &y, &a, &b, &c, &d);
	if ((a+c) <= x)
		if ((b<=y) && (d<=y))
			res += 1;  //OBS1: res deve receber 1, não precisa incrementar. Basta res=1;
	if ((a+d) <= x)
		if ((b<=y) && (c<=y))
			res += 1; //Aplica-se a OBS1
	if ((b+c) <= x)
		if ((a<=y) && (d<=y))
			res += 1; //Aplica-se a OBS1
	if ((b+d) <= x)
		if ((a<=y) && (c<=y))
			res += 1; //Aplica-se a OBS1
	if ((a+c) <= y)
		if ((b<=x) && (d<=x))
			res += 1; //Aplica-se a OBS1
	if ((a+d) <= y)
		if ((b<=x) && (c<=x))
			res += 1; //Aplica-se a OBS1
	if ((b+d) <= y)
		if ((a<=x) && (c<=x))
			res += 1; //Aplica-se a OBS1
	if ((b+c) <= y)
		if ((a<=x) && (d<=x))
			res += 1; //Aplica-se a OBS1
	if (res = 1) // Aqui vc deveria comparar se "res' é igual a "1" e não atribuir o valor de 1 à res. (igual em C é "==")
		printf("S\n");
	else
		printf("N\n");
	return 0;
}