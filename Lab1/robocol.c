#include<stdio.h>
#include<string.h>
}
int main(){
	int flag, m, n, s, i, j, l, x, cont, indice, loop=0;
	char coordenada[5]={'N','L', 'S','O'}, direcao;
	scanf("%d%d%d", &n, &m, &s);
	while(n !=0 && m!= 0 && s !=0){
		cont=0;
		flag=0;
		char salao[n][m+1], inst[s+1];

		for (i = 0; i < n; i++){
			scanf("%s", salao[i]);
		}
		for (i = 0; i < n; i++){ //Identifica Local Inicial do robo
			for (j = 0; j < m; j++){
				if ((salao[i][j]=='N') || (salao[i][j]=='S') || (salao[i][j]=='L') || (salao[i][j]=='O')){
					flag=1;
					break;
				}
			}
			if (flag) break;
		}
		switch(salao[i][j]){
			case 'N': indice=0; break;
			case 'L': indice=1; break;
			case 'S': indice=2; break;
			case 'O': indice=3; break;
		}
		salao[i][j]='.';
		scanf("%s", inst);
		x= strlen(inst);

		for(l=0; l < x;l++){
			direcao=coordenada[indice];
			if(inst[l]=='E'){
				if (indice==0)
					indice=3;
				else
					indice--;
			}
			else
				if(inst[l]=='D'){
					if(indice==3)
						indice=0;
					else
						indice++;
				}
				else
					switch(direcao){
						case 'N': {if((i>0) && (salao[i-1][j] != '#')) i--;  if(salao[i][j]=='*'){ cont++; salao[i][j]='.';} } break;
						case 'S': {if((i<n-1) && (salao[i+1][j] != '#')) i++;if(salao[i][j]=='*'){ cont++; salao[i][j]='.';} } break;
						case 'L': {if((j<m-1) && (salao[i][j+1] != '#')) j++;if(salao[i][j]=='*'){ cont++; salao[i][j]='.';} } break;
						case 'O': {if((j>0) && (salao[i][j-1] != '#')) j--;  if(salao[i][j]=='*'){ cont++; salao[i][j]='.';} } break;
					}
		}
		printf("%d\n",cont);
		scanf("%d%d%d", &n, &m, &s);
	}
	return 0;
}