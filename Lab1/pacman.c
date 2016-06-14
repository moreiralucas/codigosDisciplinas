#include<stdio.h>
#include<string.h>
int main(){
	int total=0, food=0, n, i, j;
	scanf("%d", &n);
	char tabuleiro[n][n+1];
	for (i = 0; i < n; i++){
			scanf("%s", tabuleiro[i]);
	}
	for (i = 0; i < n; ++i){
		if(i % 2 == 0)
			for ( j = 0; j < n; j++){
				if (tabuleiro[i][j]=='o'){
					food++;
				}
				if (food>total){
					total=food;
				}
				if (tabuleiro[i][j]=='A'){
					food=0;
				}
			}
		else
			for ( j = n-1; j >= 0; j--){
				if (tabuleiro[i][j]=='o'){
					food++;
				}
				if (food>total){
					total=food;
				}
				if (tabuleiro[i][j]=='A'){
					food=0;
				}
			}
	}
	printf("%d\n", total);
	return 0;
}