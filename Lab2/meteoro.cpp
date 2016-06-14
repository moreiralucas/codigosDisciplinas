#include <iostream>
#include <stdio.h>
using namespace std;
int x1, x2, y1, y2;
int verificaMeteoro(int x, int y){
	if(x<x1 || x>x2) return 0;
	if(y>y1 || y<y2) return 0;
	return 1;
}
int main (){
	int n, x, y, cont, test=1;
	cin >> x1 >> y1 >> x2 >> y2;
	while(x1,y1,x2,y2){
		cont=0;
		cin >> n;
		for (int i = 0; i < n; ++i){
			cin >> x >> y;
			if(verificaMeteoro(x,y))cont++;
		}
		cout << "Teste " << test++ << endl;
		cout << cont << endl << endl;
		cin >> x1 >> y1 >> x2 >> y2;
	}
}