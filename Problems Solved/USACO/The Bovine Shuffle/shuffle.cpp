#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

const int MAXN = 1e5;
int N, G[MAXN];
vector<int> nodes_in_cycle, vis(MAXN, 0);

void DFS1(int n){
    vis[n] = 1;
    if(vis[G[n]] == 1) nodes_in_cycle.push_back(G[n]);
    else if(vis[G[n]] == 0) DFS1(G[n]);
    vis[n] = 2;
}

void DFS2(int n, int &ret){
    ret++;
    vis[n] = 1;
    if(vis[G[n]] == 0) DFS2(G[n], ret);
    vis[n] = 2;
}

int main(){
    ifstream fin; ofstream fout;
    fin.open("shuffle.in"); fout.open("shuffle.out");
    
    fin >> N; for(int i=0; i<N; i++){fin >> G[i]; G[i]--;}
    for(int i=0; i<N; i++)
        if(vis[i] == 0) DFS1(i); 
    
    for(int i=0; i<N; i++) vis[i]=0;
    int ret = 0;
    for(int i=0; i<(int)nodes_in_cycle.size(); i++){
        if(vis[nodes_in_cycle[i]]==0) DFS2(nodes_in_cycle[i], ret);
    }

    fout << ret << "\n";

    fin.close(); fout.close();
    return 0;
}
