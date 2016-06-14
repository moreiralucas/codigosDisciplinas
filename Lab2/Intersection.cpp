#include <iostream>
#include <vector>
using namespace std;
typedef struct Ponto{
	int x;
	int y;
}ponto;
//Encontra o ponto de intersecção da reta pq e rs
ponto intersecao(ponto p, ponto q, ponto r, ponto s){
	//ponto a=q - p, b=s-r, c=ponto(p%q,r%s);
	ponto a, b, c;
	a.x=q.x-p.x; a.y=q.y-p.y;
	b.x=s.x-r.x; b.y=s.y-r.y;
	c=ponto(p,r);
	return ponto(ponto(a.x,b.x)%c,ponto(a.y,b.y)%c)/(a%b);
}
int main(){
	int n, x1, y1, x2, y2;
	//cin >> n;
	n=1;
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < 2; ++j){
			ponto p, q, r, s;
			cin >> p.x >> p.y >> q.x >> q.y;
			cin >> r.x >> r.y >> s.x >> s.y;
			//cin >> x1 >> y1 >> x2 >> y2;
			cout << intersecao(p,q,r,s) << endl;
		}
	}
	return 0;
}