#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define sz(x) (int)x.size()

const int MAXN = 2e5;

int n, m;
vector<int> G[MAXN], CC;
bool vis[MAXN];

int DFS(int u) {
    vis[u] = true;
    int ret=1;

    for(int v : G[u])
        if(!vis[v]) ret += DFS(v);

    return ret;
}

int main() {
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        int u,v; cin >> u >> v;
        G[u-1].push_back(v-1);
        G[v-1].push_back(u-1);
    }

    for(int i=0; i<n; i++)
        if(!vis[i]) CC.push_back(DFS(i));
    
    int ans=0;
    for(int i=0; i<sz(CC); i++) ans = max(ans,CC[i]);

    cout << ans << "\n";

    return 0;
}
