for(i=1;i<=m;i++)  //Dinamic Programmim
	memoria[i]=50001;
memoria[0]=0;
for(i=0;i<n;i++) //"for" da quantidade de moedas
for(j=0;j<m;j++)
if(memoria[j] != 50001 && j+moedas[i]<=m)
if(memoria[j+moedas[i]]>memoria[j]+1)
memoria[j+moedas[i]]=memoria[j]+1;
---------------------------------------------------------------------
int compara(const void * a, const void * b){return (*(int*)a - *(int*)b);}
qsort(p/*vetor*/, n/*tam vetor*/, sizeof(int), compara); //Ordena
esq=0; dir=n-1;
while(esq<=dir){//Inicia a bsuca binaria
meio=(esq + dir)/2;
if (numero < p[meio]) dir=meio-1;
else if(numero == p[meio])break;
else esq=meio+1; } //a função deve retornar meio
---------------------------------------------------------------------
tam1=strlen(s1)+1; tam2=strlen(s2)+1; //LCS
for(i=0;i<tam1;i++) matrix[0][i]=0;// Zera a linha da Matriz
for(i=0;i<tam2;i++) matrix[i][0]=0;// Zera a coluna da Matriz
//Atribui valores na Matriz
for(i=1;i<tam2;i++){
	for(j=1;j<tam1;j++){
		if(s1[j-1] == s2[i-1]){
			matrix[i][j]=matrix[i-1][j-1]+1;
		}else{if(matrix[i-1][j]>matrix[i][j-1])
				matrix[i][j]=matrix[i-1][j];
		else matrix[i][j]=matrix[i][j-1];}}}
---------------------------------------------------------------------
int custo; //Global //Edit Distance
int minimo(int a/*Sup*/, int b/*Esq*/, int c/*Diag esq*/){
a++; b++; c+=custo; int menor=a;
if(b<=menor) menor=b; if(c<=menor) menor=c; return menor; }
static int matrix[2001][2001];
tamA=strlen(a)+1;
tamB=strlen(b)+1;
for(i=0;i<tamA; i++) if(i<tamA) matrix[0][i]=i;//Init frist lin
for(i=0;i<tamB; i++) if(i<tamB) matrix[i][0]=i;//Init frist col
for(i=1;i<tamB;i++){
for(j=1;j<tamA;j++){
	if(a[j-1]==b[i-1]) custo=0;
	else custo=1;
	matrix[i][j]=minimo(matrix[i-1][j], matrix[i][j-1], matrix[i-1][j-1]);}}
---------------------------------------------------------------------
while(scanf("%d", &n) != EOF){ //KMP
char S[n+1], S2; int v[n+1]; v[0]=0;k=0;
scanf("%s ",S);
for (i=1;i<n;i++){
	while (k>0 && S[i]!=S[k]) k=v[k-1];
	if (S[i]==S[k])k++; v[i]=k;}
int imprimiu = 0; j=0;i=0;
scanf("%c", &S2);
while(S2 != '\n'){j++;
 	while(i>0 && S[i] != S2)i=v[i-1];
	if(S[i]==S2) i++;
	if(i == n){	imprimiu = 1;printf("%d\n", j-i); i=v[i-1];cont++;}
	scanf("%c", &S2);}
if (imprimiu) puts(""); //Equivalente ao printf("\n");