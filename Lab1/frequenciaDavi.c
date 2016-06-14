#include <stdio.h>
int main(){
int a, n, j, i, maior;
scanf("%d", &a);

int notas[a];
int igual[a];

for(i=0; i<a; i++){
	scanf("%d", &n);
	notas[i] = n;
	igual[i] = 0;
}
for(i=0; i<a; i++){
	for(j=0; j<a; j++){
		if((notas[i] == notas[j]) && (i != j))
			igual[j] += 1;
	}
}
printf("\n"); //coloquei esse \n pra facilitar de ver quando for olhar os casos de teste, mas submeti sem isso. 
	
maior = 0; 
for(i=0; i<a; i++){
	if(igual[i] >= maior)
		maior = igual[i];
}
printf("%d\n", notas[maior]);
return 0;
}