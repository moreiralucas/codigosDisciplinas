#include <bits/stdc++.h>

const int MAX_N = 10000;
int v[MAX_N + 1];
int tree[MAX_N * 4];

void build(int no, int esq, int dir){
	if(esq == dir){
		tree[no] = v[esq];
	}else{
		int meio = (esq + dir)/2;
		build(2*no+1, esq, meio);
		build(2*no+2, meio+1, dir);
		tree[no] = tree[2*no+1] + tree[2*no+2];
	}
}
void update(int no, int esq, int dir, int i){
	if(esq == idr){
		tree[no]= v[i];
	}else{
		int meio = (esq+dir)/2;
		if(i <= meio)
			update(2*no+1, esq, meio, i);
		else
			update(2*no+2, meio+1, dir, i);
		tree[no]=tree[2*no+1]+tree[2*no+2];
	}
}
int query(int no,int esq, int dir, int i, int j){
	if(esq == dir)
		return tree[no];
	else
		int meio = (esq+dir)/2;
	if(j <= meio)
		return query(2*no+2, meio+1, dir, i, j);
	else
		return query(2*no+1, esq, meio, i, meio)+
			query(2*no+2, meio+1, dir, meio+1, j);
}

