#define max 100
struct aluno{
	int matricula;
	char nome[30];
	float n1, n2, n3
};
Fila* cria_Fila();
void libera_Fila(Fila* fi);
int insere_Fila(Fila* fi, struct aluno al);