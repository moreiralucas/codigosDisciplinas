#include<stdio.h>
int main(){
	int l, c, r1, r2;
	scanf("%d %d %d %d", &l, &c, &r1, &r2);
	while(l != 0 && c!= 0 && r1 != 0 && r2 != 0){
		if((2*r1 < c) && (2*r1 < l) && (2*r2 < c) && (2*r2 < l) && (((2* r1) + (2*r2)) * ((2* r1) + (2*r2))) < ((c*c) + (l*l)))
			printf("S\n");
		else
			printf("N\n");

		scanf("%d %d %d %d", &l, &c, &r1, &r2);
	}
	return 0;
}