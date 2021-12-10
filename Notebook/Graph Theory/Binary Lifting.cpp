#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

const int MAXN = 1000;
const int MAXLOG = 22;

vector<int> G[MAXN];
vector<int> H;
int anc[MAXN][MAXLOG];

void DFS(int u, int p=-1) {
    if(p != -1) H[u] = H[p]+1;
    anc[u][0] = p;

    for(int i=1; i<MAXLOG; i++)
        if(anc[u][i-1] != -1) anc[u][i] = anc[anc[u][i-1]][i-1];

    for(int v : G[u]) if(v != p)
        DFS(v, u);
}

int LCA(int u, int v) {
    if(H[v] < H[u]) swap(u, v);

    for(int i=MAXLOG-1; i>-1; i--) {
        if(anc[v][i] != -1 && H[anc[v][i]] >= H[u])
            v = anc[v][i];
    }

    if(u == v) return u;

    for(int i=MAXLOG-1; i>-1; i--) {
        if(anc[u][i] != -1 && anc[u][i] != anc[v][i])
            v = anc[v][i], u = anc[u][i];
    }

    return anc[v][0];
}

int main() {
    int t; scanf("%d", &t);
    int tc=1;

    while(t--) {
        int n; scanf("%d",&n);
        vector<bool> can_be_root(n, true);
        H = vector<int>(n, 0);

        for(int u=0; u<n; u++) {
            int m; scanf("%d",&m);

            for(int j=0; j<m; j++) {
                int v; scanf("%d",&v);
                v--;

                G[u].push_back(v);
                G[v].push_back(u);

                can_be_root[v] = false;
            }
        }

        int root=0; 
        for(int i=0; i<n; i++) if(can_be_root[i])
            root = i;

        memset(anc, -1, sizeof(anc));

        DFS(root);

        int q; scanf("%d", &q);

        printf("Case %d:\n", tc++);

        while(q--) {
            int u, v; scanf("%d%d",&u,&v);    
            u--, v--;
            printf("%d\n", LCA(u, v)+1);
        }

        for(int i=0; i<n; i++) G[i].clear();
        H.clear();
    }

    return 0;
}

