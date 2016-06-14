#include <stdio.h>
#include <stdlib.h>
#define maxtam 2001
static int pilha[maxtam];
int topo;
void pilhaConstrutor(){
	topo=-1;
}
int pilhaVazia(){
	if(topo==-1)
		return 1;
	else
		return 0;
}
int pilhaCheia(){
	if(topo==maxtam-1)
		return 1;
	else
		return 0;
}
int pilhaPush(int valor){ // Push = Empilhar(Inserir)
	if(pilhaCheia())
		return 0;
	else{
		topo++;
		pilha[topo+1]=valor;
		return 1;
	}
}
int pilhaPop(int valor){ // Pop = Desempilhar
	if(pilhaVazia())
		return 0;
	else{
		valor=pilha[topo];
		topo--;
		return 1;
	}
}
int consultaPilha(int valor){
	if(pilhaVazia())
		return 0;
	else{
		valor=pilha[topo];
		return 1;
	}
}
int main(){
	int valor=-10;
	int a, b, c;
	pilhaConstrutor();
	scanf("%d", &a);
//	pilhaPush(a);
	if (pilhaVazia())
		printf("Pilha Vazia\n");
	else
		printf("Pilha não está vazia\n");

	return 0;
}