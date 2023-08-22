#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
/* ================================================= */
void fastIO() { cin.tie(0)->sync_with_stdio(0); }

int aux;
void _scan(int &x) { aux = scanf("%d", &x); }
void _scan(long long &x) { aux = scanf("%lld", &x); }
void _scan(double &x) { aux = scanf("%lf", &x); }
void _scan(char &x) { aux = scanf(" %c", &x); }
void _scan(char *x) { aux = scanf("%s", x); }
template <typename T>
void _scan(vector<T> &v) {
  for (int i = 0; i < (int)v.size(); i++) _scan(v[i]);
}
void scan() {}
template <typename T, typename... U>
void scan(T &head, U &...tail) {
  _scan(head);
  scan(tail...);
}
/* ================================================= */

typedef vector<int> vi;
typedef vector<vi> vvi;

#define sz(x) (int)x.size()

const int MAXLOG = 20;

class SegmentTree {
 private:
  int n;
  vi a, st;

  int l(int p) { return p * 2; }
  int r(int p) { return p * 2 + 1; }

  void build(int p, int L, int R) {
    if (L == R)
      st[p] = a[L];
    else {
      int m = (L + R) / 2;
      build(l(p), L, m);
      build(r(p), m + 1, R);
      st[p] = max(st[l(p)], st[r(p)]);
    }
  }

  void update(int p, int L, int R, int i, int val) {
    if (L == R)
      st[p] = val;
    else {
      int m = (L + R) / 2;
      if (i <= m)
        update(l(p), L, m, i, val);
      else
        update(r(p), m + 1, R, i, val);
      st[p] = max(st[l(p)], st[r(p)]);
    }
  }

  int rmq(int p, int L, int R, int i, int j) {
    if (L >= i && R <= j) return st[p];
    if (L > j || R < i) return -1;

    int m = (L + R) / 2;
    return max(rmq(l(p), L, m, i, j), rmq(r(p), m + 1, R, i, j));
  }

 public:
  SegmentTree() {}
  SegmentTree(int m) : n(m), st(4 * n) {}
  SegmentTree(vi &a_init) : SegmentTree(sz(a_init)) {
    a = a_init;
    build(1, 0, n - 1);
  }

  void update(int i, int val) { update(1, 0, n - 1, i, val); }

  int rmq(int i, int j) { return rmq(1, 0, n - 1, i, j); }
};

int t;
vi p, h, sz, val, in, out, a, nxt;
vvi g, anc;

SegmentTree st;

void dfs_anc(int u = 0) {
  if (p[u] != -1) h[u] = h[p[u]] + 1, anc[u][0] = p[u];

  for (int i = 1; i < MAXLOG; i++) {
    if (anc[u][i - 1] == -1) break;
    anc[u][i] = anc[anc[u][i - 1]][i - 1];
  }

  for (int v : g[u])
    if (p[u] != v) {
      p[v] = u;
      dfs_anc(v);
    }
}

void dfs_sz(int u = 0) {
  sz[u]++;
  for (int &v : g[u])
    if (v != p[u]) {
      dfs_sz(v);
      sz[u] += sz[v];
      if (sz[g[u][0]] < sz[v]) swap(g[u][0], v);
    }
}

void dfs_hld(int u = 0) {
  in[u] = t++;
  a[in[u]] = val[u];

  for (int v : g[u])
    if (v != p[u]) {
      nxt[v] = (g[u][0] == v) ? nxt[u] : v;
      dfs_hld(v);
    }

  out[u] = t;
}

int LCA(int u, int v) {
  if (h[u] < h[v]) swap(u, v);

  for (int i = MAXLOG - 1; i >= 0; i--)
    if (anc[u][i] != -1 && h[anc[u][i]] >= h[v]) u = anc[u][i];

  if (u == v) return u;

  for (int i = MAXLOG - 1; i >= 0; i--)
    if (anc[u][i] != -1 && anc[v][i] != -1 && anc[u][i] != anc[v][i])
      u = anc[u][i], v = anc[v][i];

  return anc[u][0];
}

void update_query(int u, int x) {
  val[u] = x;
  a[in[u]] = x;
  st.update(in[u], x);
}

int hld_query(int u, int l) {
  if (nxt[u] == nxt[l]) return st.rmq(in[l], in[u]);

  if (nxt[u] != u)
    return max(st.rmq(in[nxt[u]], in[u]), hld_query(p[nxt[u]], l));

  return max(val[u], hld_query(p[u], l));
}

int path_query(int u, int v) {
  return max(hld_query(u, LCA(u, v)), hld_query(v, LCA(u, v)));
}

int main() {
  int n, q;
  scan(n, q);
  p = vi(n, -1), h = vi(n, 0), sz = vi(n, 0), val = vi(n), in = vi(n, 0),
  out = vi(n, 0), a = vi(n + 7, 0), nxt = vi(n, 0);
  g = vvi(n), anc = vvi(n, vi(MAXLOG, -1));

  scan(val);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    scan(u, v);
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  dfs_anc();
  dfs_sz();
  dfs_hld();

  st = SegmentTree(a);

  while (q--) {
    int type, u, v;
    scan(type, u, v);
    if (type == 1)
      update_query(u - 1, v);
    else
      printf("%d ", path_query(u - 1, v - 1));
  }

  puts("");

  return 0;
}

// "Si puedes imaginarlo puedes programarlo" Alejandro Taboada
