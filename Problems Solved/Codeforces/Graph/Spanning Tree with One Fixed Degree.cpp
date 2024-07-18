#pragma GCC optimize("O3,unroll-loops")

#include "bits/stdc++.h"
using namespace std;

#define fst first
#define snd second
#define pb push_back
#define len(x) (int)x.size()
#define all(x) begin(x), end(x)
#define fore(i, a, b) for (auto i = a; i < b; i++)
#define forn(i, n) fore(i, 0, n)
#define dfor(i, n) for (auto i = n; i-- > 0;)
#define dbg(x) cerr << "LINE" $ __LINE__ << ":" $ #x << "=" << x << endl;
#define raya \
  cerr << "\n-----------------------------------------------------------\n"
#define $ << " " <<

template <typename T, typename U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
  os << '(' << p.first $ p.second << ')';
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  os << "[";
  forn(i, len(v)) {
    if (i) os << ", ";
    os << v[i];
  }
  os << "]";
  return os;
}

typedef long long ll;

const int INF = 1e9;

struct UnionFind {
  int n, comp;
  vector<int> uf, si, c;
  UnionFind(int _n = 0) : n(_n), comp(_n), uf(_n), si(_n, 1) {
    fore(i, 0, n) uf[i] = i;
  }
  int find(int x) { return x == uf[x] ? x : find(uf[x]); }
  bool join(int x, int y) {
    if ((x = find(x)) == (y = find(y))) return false;
    if (si[x] < si[y]) swap(x, y);
    si[x] += si[y];
    uf[y] = x;
    comp--;
    c.pb(y);
    return true;
  }
  int snap() { return c.size(); }
  void rollback(int snap) {
    while (c.size() > snap) {
      int x = c.back();
      c.pop_back();
      si[uf[x]] -= si[x];
      uf[x] = x;
      comp++;
    }
  }
};

const int MAXN = 2e5 + 100;

int n, m, D;

vector<int> g[MAXN], tree[MAXN];
int p[MAXN];

void spawning_tree() {
  UnionFind dsu(n);
  for (int u = 1; u < n; u++) {
    for (int v : g[u])
      if (v != 0) {
        if (dsu.find(u) != dsu.find(v)) {
          dsu.join(u, v);
          tree[u].push_back(v);
          tree[v].push_back(u);
        }
      }
  }
  for (int v : g[0]) {
    if (dsu.find(0) != dsu.find(v)) {
      dsu.join(0, v);
      tree[0].push_back(v);
      tree[v].push_back(0);
    }
  }
}

void dfs(int u) {
  for (int v : tree[u])
    if (v != p[u]) {
      p[v] = u;
      dfs(v);
    }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> D;
  forn(i, m) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  spawning_tree();
  p[0] = -1;
  dfs(0);

  if (len(tree[0]) > D) {
    cout << "NO\n";
    return 0;
  }

  set<int> c;
  for (int v : tree[0]) c.insert(v);

  for (int v : g[0]) {
    if (len(tree[0]) == D) break;
    if (p[v] != 0) {
      tree[0].push_back(v);
      for (int &adj : tree[v])
        if (adj == p[v]) {
          adj = -1;
          break;
        }
      for (int &adj : tree[p[v]])
        if (adj == v) {
          adj = -1;
          break;
        }
      tree[v].push_back(0);
      p[v] = 0;
    }
  }

  if (len(tree[0]) != D) {
    cout << "NO\n";
    return 0;
  }

  cout << "YES\n";
  forn(u, n) {
    for (int v : tree[u])
      if (v != p[u] && v != -1) {
        cout << u + 1 << " " << v + 1 << "\n";
      }
  }

  return 0;
}
