#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

typedef long long ll;

const int MAXN = 1e6;
const ll MOD = 1e9 + 7;

vector<int> G[MAXN];
bool vis[MAXN];

void DFS(int u) {
    vis[u] = true;
    for(int v : G[u]) if(!vis[v])
        DFS(v);
}

int main() {
    int t; scanf("%d",&t);
    
    while(t--) {
        int n; scanf("%d",&n); 
        int a[2][n];
        for(int i=0; i<2; i++)
            for(int j=0; j<n; j++)
                scanf("%d", a[i]+j);

        for(int i=0; i<n; i++) {
            G[a[0][i]].push_back(a[1][i]+n); 
            G[a[1][i]+n].push_back(a[0][i]);

            G[a[0][i]].push_back(a[0][i]+n);
            G[a[0][i]+n].push_back(a[0][i]);
        }

        ll ans=1;

        for(int i=1; i<=n+n; i++) {
            if(!vis[i]) { DFS(i); ans = (ans * 2) % MOD; }
        }

        printf("%lld\n", ans);

        for(int i=1; i<=n+n; i++) G[i].clear();
        memset(vis, false, sizeof(vis));
    }

    return 0;
}
