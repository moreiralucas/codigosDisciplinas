#include <stdio.h>

int main(void) {
	int d, seq, j, i, soma=0, Case=0;
	while(scanf("%d", &d)!= EOF){
		int vet[d+1];
		Case++;
		seq=1;
		for(i=0;i<d;i++)
			scanf("%d", &vet[i]);
		for(i=2; i<d;i++){
			soma=0;	
			j=i;
			while(soma<=vet[i] && j>0){
				soma+=vet[--j];
				if(soma==vet[i]){
					seq=0;
					break;
				}

			}
			if(soma==vet[j]);
				break;
		}
		printf("Case #%d: ", Case);
		for(i=0;i<d;i++)
			printf("%d ", vet[i]);
		if(seq)
			printf("\nThis is an A-sequence.\n");
		else
			printf("\nThis is not an A-sequence.\n");
		
	}
	return 0;
}