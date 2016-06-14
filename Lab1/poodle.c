#include <stdio.h>
int main(){
	long int n, p, r, i; 
	scanf("%li%li", &n, &p);
	while (n!=0){
		if (n%p > 0 ){  // (n+p)/p sempre dara um numero certo de paginas. ex: 7/3 = 2, mas devia ser 3 paginas, (7+3)/3 == 3 ! good job :D
			r = (n/p) + 1;
		} 
		if((r < 6) && (n%p == 0)){ // strlen(poodle) == 6 ou seja, <=
			printf("Poodle\n");
		}
		if((r >= 6) && (r <= 20)){ // >
			if((n%p) > 0){ 
				r = r - 3;
			}
			printf("P");
			for (i=0; i<r; i++){ 
				printf("o");
			}
			printf("dle\n");
		}
		if(r > 20){
			printf("Poooooooooooooooodle\n");
		}
		scanf("%li%li", &n, &p);
	} 
	return 0;
}