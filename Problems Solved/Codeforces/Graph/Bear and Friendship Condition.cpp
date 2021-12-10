#include <cstdio>
#include <vector>
using namespace std;

typedef long long ll;

#define sz(x) (int)x.size()

const int MAXN = 150007;

int n, m;
bool vis[MAXN];
vector<int> G[MAXN];

void DFS(int u, vector<int>& cc) {
    cc.push_back(u);
    vis[u] = true;
    for(int v : G[u]) if(!vis[v])
        DFS(v, cc);
}

int main() {
    scanf("%d%d",&n,&m);
    for(int i=0; i<m; i++) {
        int u,v; scanf("%d%d",&u,&v);
        G[u-1].push_back(v-1);
        G[v-1].push_back(u-1);
    }

    bool can = true;

    for(int i=0; i<n; i++) {
        if(!vis[i]) {
            vector<int> cc;
            DFS(i, cc);
            ll cnt=0;
            ll x = sz(cc);

            for(int u : cc) 
                cnt += (ll)sz(G[u]);

            can &= (cnt == x*(x-1));
        }
    }

    (can)? puts("YES") : puts("NO");

    return 0;
}
