// https://www.spoj.com/problems/SUBTLEBA/

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

struct node {
  int to, w;
};

struct edge {
  int u, v, w;
  bool operator<(const edge& e) const { return w < e.w; }
  bool operator>(const edge& e) const { return w > e.w; }
};

struct union_find {
  vector<int> p;
  vector<int> sz;

  union_find(int n) {
    p = vector<int>(n);
    sz = vector<int>(n, 1);
    for (int i = 0; i < n; i++) p[i] = i;
  }

  int find(int x) { return (p[x] == x) ? x : p[x] = find(p[x]); }

  void merge(int u, int v) {
    int pu = find(u), pv = find(v);
    if (sz[pu] < sz[pv]) swap(pu, pv);

    sz[pu] += sz[pv];
    p[pv] = pu;
  }
};

const int MAXN = 2e4, MAXM = 1e5, MAXLOG = 22, INF = 1e9;

vector<node> tree[MAXN];
int H[MAXN], anc[MAXN][MAXLOG], min_anc[MAXN][MAXLOG];

void DFS(int u, int p = -1, int val = INF) {
  if (p != -1) H[u] = H[p] + 1;
  anc[u][0] = p;
  min_anc[u][0] = val;

  for (int i = 1; i < MAXLOG; i++) {
    if (anc[u][i - 1] != -1) {
      anc[u][i] = anc[anc[u][i - 1]][i - 1];
      min_anc[u][i] = min(min_anc[u][i - 1], min_anc[anc[u][i - 1]][i - 1]);
    }
  }

  for (auto& [v, w] : tree[u])
    if (v != p) DFS(v, u, w);
}

int solve(int u, int v) {
  if (H[v] < H[u]) swap(u, v);

  int ret = INF;

  for (int i = MAXLOG - 1; i > -1; i--) {
    if (anc[v][i] != -1 && H[anc[v][i]] >= H[u]) {
      ret = min(ret, min_anc[v][i]);
      v = anc[v][i];
    }
  }

  if (v == u) return ret;

  for (int i = MAXLOG - 1; i > -1; i--) {
    if (anc[u][i] != -1 && anc[u][i] != anc[v][i]) {
      ret = min(ret, min(min_anc[u][i], min_anc[v][i]));
      u = anc[u][i], v = anc[v][i];
    }
  }

  ret = min(ret, min(min_anc[u][0], min_anc[v][0]));

  return ret;
}

int main() {
  int n, m, s;

  while (scanf("%d%d%d", &n, &m, &s) != EOF) {
    edge e[m];

    for (int i = 0; i < m; i++) {
      int u, v, w;
      scanf("%d%d%d", &u, &v, &w);
      u--, v--;
      e[i] = {u, v, w};
    }

    sort(e, e + m, greater<edge>());

    union_find uf(n);

    for (int i = 0; i < n; i++) {
      auto& [u, v, w] = e[i];
      if (uf.find(u) != uf.find(v)) {
        uf.merge(u, v);
        tree[u].push_back({v, w});
        tree[v].push_back({u, w});
      }
    }

    memset(anc, -1, sizeof(anc));
    memset(min_anc, 0, sizeof(min_anc));
    memset(H, 0, sizeof(H));

    DFS(0);

    while (s--) {
      int u, v;
      scanf("%d%d", &u, &v);
      u--, v--;
      printf("%d\n", solve(u, v));
    }

    for (int i = 0; i < n; i++) tree[i].clear();
  }

  return 0;
}
