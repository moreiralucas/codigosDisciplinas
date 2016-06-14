#include<stdio.h>
int main(){
	int i, j;
	char table[9][8];
	for (j = 0; j < 8; ++j){
		for (i = 0; i < 9; ++i){
			scanf("%c", &table[j][i]);
		}
	}
	for (j = 0; j < 8; ++j){
		for (i = 0; i < 8; ++i){
			printf("%c", table[j][i]);
		}
		printf("\n");
	}

	return 0;
}