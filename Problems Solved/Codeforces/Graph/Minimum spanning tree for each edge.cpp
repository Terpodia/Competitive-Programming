#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;

struct edge {
    int u,v; ll w; int index;
    bool operator<(const edge& e) const { return w < e.w; }
};

struct node {
    int to; ll w;
};

struct union_find {
    vector<int> p, sz;

    union_find(int n) { 
        p = vector<int>(n);
        sz = vector<int>(n,1);
        for(int i=0; i<n; i++) p[i]=i;
    }

    int find(int x) { return (p[x] != x)? p[x] = find(p[x]) : x; }

    bool merge(int u, int v) {
        int pu=find(u), pv=find(v);
        if(pu == pv) return false;

        if(sz[pu] < sz[pv]) swap(pu,pv);
        sz[pu] += sz[pv];
        p[pv] = pu;

        return true;
    }
};

const int MAXN = 2e5, MAXLOG = 24;
const ll INF = 1e18;

vector<node> tree[MAXN];
int anc[MAXN][MAXLOG];
ll max_anc[MAXN][MAXLOG];
int H[MAXN];

void DFS(int u,int p=-1,ll val=-INF) {
    if(p != -1) H[u] = H[p]+1;  
    anc[u][0] = p; max_anc[u][0] = val;

    for(int i=1; i<MAXLOG; i++) {
        if(anc[u][i-1] != -1)
            anc[u][i] = anc[anc[u][i-1]][i-1],
            max_anc[u][i] = max(max_anc[u][i-1], max_anc[anc[u][i-1]][i-1]);
    }

    for(auto& [v,w] : tree[u]) if(v != p)
        DFS(v,u,w);
}

ll calc(int u, int v) {
    if(H[v] < H[u]) swap(u,v);

    ll ret=-INF;

    for(int i=MAXLOG-1; i>-1; i--) {
        if(anc[v][i] != -1 && H[anc[v][i]] >= H[u])
            ret = max(ret, max_anc[v][i]), v = anc[v][i];
    }

    if(u == v) return ret;

    for(int i=MAXLOG-1; i>-1; i--) {
        if(anc[u][i] != -1 && anc[u][i] != anc[v][i])
            ret = max(ret, max(max_anc[u][i], max_anc[v][i])),
            u = anc[u][i], v = anc[v][i];
    }

    ret = max(ret, max(max_anc[u][0], max_anc[v][0]));

    return ret;
}

int main() {
    int n, m; scanf("%d%d",&n,&m);

    vector<edge> e(m);
    bool in_mst[m]; memset(in_mst, false, sizeof(in_mst)); 
    ll mst=0;

    for(int i=0; i<m; i++) {
        int u,v; ll w; scanf("%d%d%lld",&u,&v,&w); 
        u--, v--;
        e[i] = { u, v, w, i };        
    }

    vector<edge> query = e;

    sort(e.begin(), e.end());

    union_find uf(n);

    for(int i=0; i<m; i++) {
        auto& [u,v,w,j] = e[i];
        
        if(uf.merge(u,v)) 
            in_mst[j] = true, mst += w;
    }

    for(int i=0; i<m; i++) {
        if(in_mst[i]) {
            auto& [u,v,w,j] = query[i];
            tree[u].push_back({v,w});
            tree[v].push_back({u,w});
        }
    }

    memset(anc, -1, sizeof(anc));

    DFS(0);

    for(int i=0; i<m; i++) {
        if(in_mst[i]) printf("%lld\n",mst);

        else {
            auto& [u,v,w,j] = query[i];
            printf("%lld\n", mst - calc(u,v) + w);
        }
    }

    return 0;
}

