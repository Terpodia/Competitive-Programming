#include <fstream>
#include <sched.h>
#include <vector>
using namespace std;

const int MAXN = 1e5;
vector<bool> vis(MAXN, false);
vector<int> G[MAXN];

int component[MAXN];
char type[MAXN];

int N, M, index = 0;

void DFS(int i){
    vis[i] = true;
    component[i] = index;
    for(int v : G[i])
        if(!vis[v] && type[v] == type[i]) DFS(v);
}

void fullDFS(){
    for(int i=0; i<N; i++){
        if(!vis[i]){
            DFS(i);
            index++;
        }
    }
}

int main(){
    ifstream fin; ofstream fout;
    fin.open("milkvisits.in");
    fout.open("milkvisits.out");

    fin >> N >> M;
    
    for(int i=0; i<N; i++) fin >> type[i];

    for(int i=0; i<N-1; i++){
        int x, y; fin >> x >> y;
        G[x-1].push_back(y-1); G[y-1].push_back(x-1);
    }

    fullDFS();
    
    while(M--){
        int A, B; char C;
        fin >> A >> B >> C;
        if(component[A-1] != component[B-1] || type[A-1] == C)
            fout << "1";

        else fout << "0";
    }

    fin.close(); fout.close();
    return 0;
}
