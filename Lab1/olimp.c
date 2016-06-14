#include<stdio.h>
int main(){
	int i, j, n, m, menor_i, aux, aux2, o, p, b;
	scanf("%d %d", &n, &m);
	int medalhaPais[n], indicePais[n];
	for (i = 0; i <= n; ++i){
		indicePais[i]=i;
		medalhaPais[i]=0;
	}
	for (i = 1; i <= m; ++i){
		scanf("%d %d %d", &o, &p, &b);
		medalhaPais[o]++;
		medalhaPais[p]++;
		medalhaPais[b]++;
	}
//	for (i = 1; i <= m; ++i){
//		printf("%d\n",medalhaPais[i] );
//	}
	for (j = 1; j <= n-1; ++j){
		menor_i=j;
		for (i = j+1; i <= n; ++i)
			if (medalhaPais[i] > medalhaPais[menor_i] || (medalhaPais[i]==medalhaPais[menor_i] && indicePais[i]<indicePais[menor_i]))
//			if (medalhaPais[i] > medalhaPais[menor_i])
				menor_i=i;
		aux=medalhaPais[j];
		aux2=indicePais[j];

		medalhaPais[j]=medalhaPais[menor_i];
		indicePais[j]=indicePais[menor_i];
		
		medalhaPais[menor_i]=aux;
		indicePais[menor_i]=aux2;

	}
	for (i = 1; i <= n; ++i){
		printf("%d ", indicePais[i] );
//		printf("IndicePais:%d MedalhaPais:%d \n", indicePais[i], medalhaPais[i]);
	}
	printf("\n");
	return 0;
}