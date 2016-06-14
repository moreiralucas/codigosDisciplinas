#include<stdio.h>
int main(){
	int teste=0, n, i, j, numeros[10][10], aux[10][12], repeat[10], menor_i, result;
	char letras[10][13];
	scanf("%d", &n); //quantidade de linhas de entrada
	while(n){
		for(i=0; i< n; i++){					//Entrada
			for(j=0; j<10; j++){
				scanf("%d", &numeros[i][j]);	//Ler os numeros
				repeat[j]=0;
			}
			scanf("%[^\n]s\n", letras[i]);		//Ler as letras
			
		}	
		for(i=0; i<n; i++){
			for(j=1; j<13; j+=2){
				switch(letras[i][j]){
					case 'A':{ aux[i][j-1]=numeros[i][0];aux[i][j]=numeros[i][1]; } break;
					case 'B':{ aux[i][j-1]=numeros[i][2];aux[i][j]=numeros[i][3]; } break;
					case 'C':{ aux[i][j-1]=numeros[i][4];aux[i][j]=numeros[i][5]; } break;
					case 'D':{ aux[i][j-1]=numeros[i][6];aux[i][j]=numeros[i][7]; } break;
					case 'E':{ aux[i][j-1]=numeros[i][8];aux[i][j]=numeros[i][9]; } break;
				}
			}
			
		}
		printf("Teste %d\n", ++teste);
		for (j = 0; j < 12; j+=2){				//Seleciono a senha correspondente
			for (i = 0; i < 10; i++){
				repeat[i]=0;
			}
			menor_i=0;
			for(i = 0; i < n; i++){
				repeat[aux[i][j]]++; repeat[aux[i][j+1]]++;
			}
			for (i = 0; i < 10; i++){
				if(repeat[i] > menor_i){
					menor_i=repeat[i];
					result=i;
				}
			}
			printf("%d ", result);
		}
		printf("\n\n");		
		scanf("%d", &n);
	}
return 0;
}
