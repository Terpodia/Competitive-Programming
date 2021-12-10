#include <cstdio>
#include <vector>
using namespace std;

const int MAXN = 1e5;

vector<int> G[MAXN];
bool vis[MAXN];

int DFS(int u, int p, int& ans) {
    vis[u] = true;
    int cnt=1;

    for(int v : G[u]) {
        if(!vis[v]) cnt += DFS(v, u, ans);
    }

    if(cnt%2 == 0 && p != -1) ans++;

    return cnt;
}

int main() {
    int n; scanf("%d",&n);

    for(int i=0; i<n-1; i++) {
        int u,v; scanf("%d%d",&u,&v);
        G[u-1].push_back(v-1);
        G[v-1].push_back(u-1);
    }

    if(n%2) puts("-1");

    else {
        int ans=0;
        DFS(0, -1, ans);
        printf("%d\n", ans);
    }

    return 0;
}
