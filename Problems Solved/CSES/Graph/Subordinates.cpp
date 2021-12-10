#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

const int MAXN = 2 * 1e5;
int N;

vvi G(MAXN);
vi subtree_size(MAXN, 1);

void fastIO(){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
}

void DFS(int node){
    for(int child : G[node]){
        DFS(child);
        subtree_size[node] += subtree_size[child];
    } 
}

int main(){
    fastIO();
    cin >> N;

    for(int i=0; i<N-1; i++){
        int dad; cin >> dad;
        G[dad-1].push_back(i+1);
    }

    DFS(0);
    for(int i=0; i<N; i++)
        cout << subtree_size[i]-1 << " ";

    cout << "\n";
    return 0;
}
