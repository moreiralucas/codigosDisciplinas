#include <stdio.h>
#define max 700
static int terreno[max][max];
void imprimeMatriz(int n,int terreno[][max]){
	int i,j;
	for (i = 0; i < n; ++i){
		for (j = 0; j < n; ++j){
			printf("%d ", terreno[i][j]);
		}
		printf("\n");
	}

}
int main(){
	int q, i, j, x, y, l, c, n, soma, cerca, area;
//	int terreno[max][max];
	while(scanf("%d", &n), n){
		cerca=0;
		area=0;
		for(i=0;i<max; i++)		//Zerando a matriz
			for(j=0; j<max; j++)
				terreno[i][j]=0;

		for(q=0; q < n; q++){
			scanf("%d%d%d%d", &x, &y, &l, &c);
			//printf("x:%d y:%d l:%d c:%d\n", x, y, l, c);
			for(i=y; i<y+c; i++)
				for(j=x; j<x+l; j++)
					terreno[i][j]=1;
			//imprimeMatriz(10,terreno); printf("----------------------\n");
		}
		
		for(i=0;i<max; i++)
			for(j=0;j<max; j++){
				if(terreno[i][j]==1){
					area++;
					if(terreno[i-1][j]==0 /*|| i-1 < 0*/)
						cerca++;
					if(terreno[i+1][j]==0 /*|| i+1 >= max */)
						cerca++;
					if(terreno[i][j-1]==0/* || j-1 < 0*/)
						cerca++;
					if(terreno[i][j+1]==0 /*|| j+1 >= max*/)
						cerca++;
				}
			}
	//	imprimeMatriz(10,terreno);
		printf("%d %d\n",area, cerca);
	}
	return 0;
}
