#include <stdio.h>
#define MA 100001
int main (){
	int n, q, i, j, a, x, r, maior;
	scanf("%d%d", &n, &q);
	int matrix[n][n];
	static int freq[MA];

	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			matrix[i][j]=0;
			
	for(i=0; i< q;i++){
		scanf("%d", &a);
		if(a == 1 || a == 2){
			scanf("%d%d", &x, &r);
			if(a == 1){
				for(j=0;j<n;j++)
					matrix[x][j]=r;
			}else{
				for(j=0;j<n;j++)
					matrix[j][x]=r;
			}
		}else{
			scanf("%d", &x);
			if(x == 3){
				maior=0;
				for(j=0;j<MA;j++)
					freq[j]=0;

				for(j=0;j<n;j++)
					freq[matrix[x][j]]++;

				for(j=MA-1;j>=0;j--)
					if(freq[j] > maior)
						maior=freq[j];
				printf("%d\n", maior);
			}else{
				maior=0;
				for(j=0;j<MA;j++)
					freq[j]=0;				

				for(j=0;j<n;j++)
					freq[matrix[j][x]]++;

				for(j=MA-1;j>=0;j--)
					if(freq[j] > maior)
						maior=freq[j];


				printf("%d\n", maior);
			}
		}
	}
	for(i=0; i<n;i++){
		for(j=0; j<n;j++)
			printf("%d ", matrix[i][j]);
		printf("\n");
	}		
	return 0;
}
