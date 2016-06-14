#include <iostream>
using namespace std;
#define TAM 10
#define TAMF 10000

int incl[] = {-1,  0, 0, 1};
int incc[] = { 0, -1, 1, 0};
int caverna[TAM][TAM];
int N, M;
bool dentro_caverna(int l, int c){
    return l >= 0 && l < N && c >= 0 && c < M;
}
int bfs(int l, int c){
    int ini = 0, fim = 0;
    int larguras[TAMF], comprimentos[TAMF], distOrigem[TAMF];
    int dist = 0;
    
    // adiciona um elemento a fila
    larguras[fim] = l;
    comprimentos[fim] = c;
    distOrigem[fim] = 0;
    fim++;
    
    while (ini != fim){//ini e fim são inicializados com zero
        l = larguras[ini];
        c = comprimentos[ini];
        dist = distOrigem[ini];
        ini++;
        
        if (caverna[l][c] == 0) return dist;
        else if (caverna[l][c] == 1){
            for (int i = 0; i < 4; i++){
                if (dentro_caverna(l + incl[i], c + incc[i]) && caverna[l + incl[i]][c + incc[i]] < 2){
                    larguras[fim] = l + incl[i];
                    comprimentos[fim] = c + incc[i];
                    distOrigem[fim] = dist + 1;
                    fim++;
                }
            }
        }
        caverna[l][c] = 2;
    }
    return -1;
}
int main(){
    int x, y;
    cin >> N >> M;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            cin >> caverna[i][j];
            if (caverna[i][j] == 3){
                x = i;
                y = j;
                caverna[i][j] = 1;
            }
        }
    }

    cout << bfs(x, y) << endl;
    return 0;
}