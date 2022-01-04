#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

void fastIO() { cin.tie(0)->sync_with_stdio(0); }

#define sz(x) (int)x.size()

const int MAXN = 10010, MAXLOG = 20;

class SegmentTree {
  private:
    int n;
    vector<int> st, a;

    int l(int p) { return 2*p; }
    int r(int p) { return 2*p+1; }

    void build(int p, int L, int R) {
      if (L == R) st[p] = a[L];
      else {
        int m = (L+R)/2;
        build(l(p), L, m);
        build(r(p), m+1, R);
        st[p] = max(st[l(p)], st[r(p)]);
      }
    }

    void update(int p, int L, int R, int j, int v) {
      if (L == R) st[p] = v;
      else {
        int m = (L+R)/2;
        if (j <= m) update(l(p), L, m, j, v);
        else update(r(p), m+1, R, j, v);
        st[p] = max(st[l(p)], st[r(p)]);
      }
    }

    int rmq(int p, int L, int R, int i, int j) {
      if (L >= i && R <= j) return st[p];
      if (L > j || R < i) return -1;

      int m = (L+R)/2;
      return max(rmq(l(p), L, m, i, j), rmq(r(p), m+1, R, i, j));
    }

  public: 
    SegmentTree() { }

    SegmentTree(int m) : n(m), st(4*n, -1) { }

    SegmentTree(int b[], int m) : SegmentTree(m) {
      for (int i=0; i<n; i++) a.push_back(b[i]);
      build(1, 0, n-1);
    }

    void update(int j, int v) {
      update(1, 0, n-1, j, v);
    }

    int rmq(int i, int j) {
      return rmq(1, 0, n-1, i, j);
    }
};

struct edge {
  int u, v, w;
};

int N;

vector<pair<int,int>> G[MAXN];

int anc[MAXN][MAXLOG], sz[MAXN], h[MAXN], t, in[MAXN], nxt[MAXN], a[MAXN];

pair<int,int> p[MAXN];

edge edges[MAXN];

SegmentTree st;

void dfs_anc(int u=0) {
  if (p[u].first != -1) {
    anc[u][0] = p[u].first; 
    h[u] = h[p[u].first]+1; 
  }

  for (int i=1; i<MAXLOG; i++) {
    if (anc[u][i-1] == -1) break;
    anc[u][i] = anc[anc[u][i-1]][i-1];
  }

  for (auto [v, j] : G[u]) if (p[u].first != v) {
    p[v] = { u, j };
    dfs_anc(v);
  }
}

int LCA(int u, int v) {
  if (h[u] < h[v]) swap(u, v);
  for (int i = MAXLOG-1; i>=0; i--) {
    if (anc[u][i] != -1 && h[anc[u][i]] >= h[v])
      u = anc[u][i];
  }

  if (u == v) return u;

  for (int i = MAXLOG-1; i>=0; i--) {
    if (anc[u][i] != -1 && anc[v][i] != -1 && anc[u][i] != anc[v][i])
      u = anc[u][i], v = anc[v][i];
  }

  return anc[u][0];
}

void dfs_sz(int u=0) {
  sz[u] = 1; 
  for (auto& [v, j] : G[u]) if (p[u].first != v) {
    dfs_sz(v);
    sz[u] += sz[v];
    if (sz[v] > sz[G[u][0].first]) { 
      swap(G[u][0].first, v);
      swap(G[u][0].second, j);
    }
  }
}

void dfs_hld(int u=0) {
  for (auto [v, j] : G[u]) if (p[u].first != v) {
    a[t] = edges[j].w;
    in[j] = t++;
    nxt[v] = (v == G[u][0].first) ? nxt[u] : v;
    dfs_hld(v);
  }
}

void update_query(int i, int w) {
  st.update(in[i], w);
  a[in[i]] = w;
  edges[i].w = w;
}

int hld_query(int u, int l) {
  if (u == l) return 0;

  if (nxt[u] == nxt[l]) 
    return st.rmq(in[G[l][0].second], in[p[u].second]);
  
  if (u != nxt[u]) 
    return max(st.rmq(in[G[nxt[u]][0].second], in[p[u].second]), hld_query(nxt[u], l));
  
  return max(edges[p[u].second].w, hld_query(p[u].first, l));
}

int path_query(int u, int v) {
  int l = LCA(u, v);
  return max(hld_query(u, l), hld_query(v, l));
}

int main() {
  fastIO();
  int tc; cin >> tc;

  while (tc--) {
    cin >> N;

    for (int i=0; i<N-1; i++) {
      int u, v, c;
      cin >> u >> v >> c; 
      u--, v--;
      G[u].push_back(make_pair(v, i)); 
      G[v].push_back(make_pair(u, i)); 

      edges[i] = { u, v, c };
    }

    p[0] = { -1, -1 };
    nxt[0] = 0, h[0] = 0, t = 0;

    memset(anc, -1, sizeof(anc));

    dfs_anc(); dfs_sz(); dfs_hld();

    st = SegmentTree(a, N-1);
    string s;

    while (cin >> s && s != "DONE") {
      if (s == "CHANGE") {
        int i, w; cin >> i >> w;
        update_query(i-1, w);
      } 
      else {
        int u, v; cin >> u >> v;
        cout << path_query(u-1, v-1) << "\n";
      }
    }

    for (int i=0; i<N; i++) G[i].clear();
  }

  return 0;
}
 
