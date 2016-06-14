#include <iostream>

using namespace std;
int verifica(int L, int C, int R1, int R2){
	int somaRaio=R1+R2;
	int lr= L- somaRaio;
	int cr= C- somaRaio;
	if(min(L,C) < max(R1,R2)*2) return 0;
	if((lr*lr)+(cr*cr) >= (somaRaio*somaRaio))
		return 1;
	else
		return 0;
}
int main(){
	int l, c, r1, r2;
	cin >> l >> c >> r1 >> r2;
	while(l,c,r1,r2){
		if(verifica(l,c,r1,r2))
			cout << "S" << endl;
		else
			cout << "N" << endl;
		cin >> l >> c >> r1 >> r2;
	}
	return 0;
}
