#include<stdio.h>
#include<string.h>
#define max1 10001
#define max2 100001
int main (){
	int j, q, m, t, i, k=4, notas;
	static int notasM[max2],notasT[max1];
	char melodia[max2][2], trecho[max1][2];
	scanf("%d %d", &m, &t);
	while(k--){
		q=0;
		for(i=0; i<m; i++){ notas=-1;
			scanf("%s", melodia[i]); 
			if(melodia[i][0]== 'A' && melodia[i][1]=='\0'){ notas = 1; }
			if(melodia[i][0]== 'A' && melodia[i][1]=='#'){ notas = 2; }
			if(melodia[i][0]== 'B' && melodia[i][1]=='b'){ notas = 2; }
			if(melodia[i][0]== 'B' && melodia[i][1]=='\0'){ notas = 3; }
			if(melodia[i][0]== 'C' && melodia[i][1]=='b'){ notas = 3; }
			if(melodia[i][0]== 'C' && melodia[i][1]=='\0'){ notas = 4; }
			if(melodia[i][0]== 'B' && melodia[i][1]=='#'){ notas = 4; }
			if(melodia[i][0]== 'D' && melodia[i][1]=='b'){ notas = 5; }
			if(melodia[i][0]== 'C' && melodia[i][1]=='#'){ notas = 5; }
			if(melodia[i][0]== 'D' && melodia[i][1]=='\0'){ notas = 6; }
			if(melodia[i][0]== 'D' && melodia[i][1]=='#'){ notas = 7; }
			if(melodia[i][0]== 'E' && melodia[i][1]=='b'){ notas = 7; }
			if(melodia[i][0]== 'E' && melodia[i][1]=='\0'){ notas = 8; }
			if(melodia[i][0]== 'F' && melodia[i][1]=='b'){ notas = 8; }
			if(melodia[i][0]== 'F' && melodia[i][1]=='\0'){ notas = 9; }
			if(melodia[i][0]== 'E' && melodia[i][1]=='#'){ notas = 9; }
			if(melodia[i][0]== 'F' && melodia[i][1]=='#'){ notas = 10; }
			if(melodia[i][0]== 'G' && melodia[i][1]=='b'){ notas = 10; }
			if(melodia[i][0]== 'G' && melodia[i][1]=='\0'){ notas = 11; }
			if(melodia[i][0]== 'G' && melodia[i][1]=='#'){ notas = 12; }
			if(melodia[i][0]== 'A' && melodia[i][1]=='b'){ notas = 12; }	
			notasM[i]=notas; printf("%d ", notasM[i]);
		} printf("\n");
		for(i=0; i<t; i++){; notas=-1;
			scanf("%s", trecho[i]);
			if(trecho[i][0]== 'A' && trecho[i][1]=='\0'){ notas = 1; }
			if(trecho[i][0]== 'A' && trecho[i][1]=='#'){ notas = 2; }
			if(trecho[i][0]== 'B' && trecho[i][1]=='b'){ notas = 2; }
			if(trecho[i][0]== 'B' && trecho[i][1]=='\0'){ notas = 3; }
			if(trecho[i][0]== 'C' && trecho[i][1]=='b'){ notas = 3; }
			if(trecho[i][0]== 'C' && trecho[i][1]=='\0'){ notas = 4; }
			if(trecho[i][0]== 'B' && trecho[i][1]=='#'){ notas = 4; }
			if(trecho[i][0]== 'D' && trecho[i][1]=='b'){ notas = 5; }
			if(trecho[i][0]== 'C' && trecho[i][1]=='#'){ notas = 5; }
			if(trecho[i][0]== 'D' && trecho[i][1]=='\0'){ notas = 6; }
			if(trecho[i][0]== 'D' && trecho[i][1]=='#'){ notas = 7; }
			if(trecho[i][0]== 'E' && trecho[i][1]=='b'){ notas = 7; }
			if(trecho[i][0]== 'E' && trecho[i][1]=='\0'){ notas = 8; }
			if(trecho[i][0]== 'F' && trecho[i][1]=='b'){ notas = 8; }
			if(trecho[i][0]== 'F' && trecho[i][1]=='\0'){ notas = 9; }
			if(trecho[i][0]== 'E' && trecho[i][1]=='#'){ notas = 9; }
			if(trecho[i][0]== 'F' && trecho[i][1]=='#'){ notas = 10; }
			if(trecho[i][0]== 'G' && trecho[i][1]=='b'){ notas = 10; }
			if(trecho[i][0]== 'G' && trecho[i][1]=='\0'){ notas = 11; }
			if(trecho[i][0]== 'G' && trecho[i][1]=='#'){ notas = 12; }
			if(trecho[i][0]== 'A' && trecho[i][1]=='b'){ notas = 12; }	
			notasT[i]=notas; printf("%d ", notasT[i]);
		} printf("\n");
		printf("m:%d\n",m );
		for (i = 0; i < m; i++){ printf("i:%d ", i);
			q=0;
			if(notasM[i]==notasT[q])
				for(j=i+1; j<t; j++){
					q++; printf("Entrou(q:%d) i:%d j:%d\n", q, i, j-1); 
					if(notasM[j]==notasT[q] )
						printf("Plagio\n");
					else{
						q=0; printf("Not plagio\n"); 
					}
				}
		} printf("\n\n");
		scanf("%d%d", &m, &t);
	}
	return 0;
}
