#include <iostream>
using namespace std;
int main (){
	int i,j,k,v[101];
	string S;
	cin >> S;
	int t=S.size();
	v[0]=0;
	k=0;
	for (i=1;i<t;i++){
		while (k>0 && S[i]!=S[k])
			k=v[k-1];
		if (S[i]==S[k]){
			/*v[i]=*/k++;
		}
		v[i]=k;
	}
	cout << S << endl;
	for (i=0;i<t;i++)
		cout << v[i];
	cout << endl;
	return 0;
}
