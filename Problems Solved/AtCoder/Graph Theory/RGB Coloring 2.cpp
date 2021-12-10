#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int MAXN = 20, xd[3][2] = { {2, 3}, {1, 3}, {1, 2} };

int n, m;
vector<int> G[MAXN];
bool vis[MAXN];

void DFS(int u, vector<int>& nodes) {
    vis[u] = true;
    nodes.push_back(u);
    for(int v : G[u]) if(!vis[v]) DFS(v, nodes);
}

void can(int u, int parent, bool& flag, vector<int>& colors, vector<int>& id, int msk) {
    int index=id[u];

    colors[u] = xd[parent-1][(msk & (1<<index)) != 0];

    for(int v : G[u]) {
        if(colors[v] && colors[v] == colors[u]) { flag = false; return; }
        if(!colors[v]) can(v, colors[u], flag, colors, id, msk);
    }
}

ll calc(vector<int> nodes) {
    ll ans=0;
    int k=(int)nodes.size();
    vector<int> id(20, -1);

    for(int i=0; i<k; i++) id[nodes[i]] = i-1;

    for(int msk=0; msk < (1<<(k-1)); msk++) {
        for(int _=0; _<3; _++) {
            bool flag=true;
            vector<int> colors(n, 0);
            colors[nodes[0]] = _+1;

            for(int v : G[nodes[0]]) 
                if(!colors[v]) can(v, _+1, flag, colors, id, msk); 
            
            if(flag) ans++;
        }
    }

    return ans;
}

int main() {
    scanf("%d%d",&n,&m);
    for(int i=0; i<m; i++) {
        int u, v; scanf("%d%d",&u,&v);
        G[u-1].push_back(v-1);
        G[v-1].push_back(u-1);
    }

    ll ans=1;

    for(int i=0; i<n; i++) {
        if(!vis[i]) {
            vector<int> nodes;
            DFS(i, nodes);
            ans *= calc(nodes);
        }
    }

    printf("%lld\n", ans);

    return 0;
}
