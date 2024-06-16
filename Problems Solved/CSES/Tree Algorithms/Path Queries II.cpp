#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>
// #include <bits/stdc++.h>
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

const int MAXN = 2e5 + 10;
const int INF = 1e9;

#define op max
#define NEUT -INF

struct STree {
  vector<int> st;
  int n;
  STree(int _n) : st(_n * 2, NEUT), n(_n) {}
  STree(int _n, int *a) : st(_n * 2, NEUT), n(_n) {
    fore(i, 0, n) st[n + i] = a[i];
    build();
  }
  void build() {
    for (int i = n - 1; i > 0; i--) st[i] = op(st[i << 1], st[(i << 1) | 1]);
  }
  void upd(int p, int v) {
    for (st[p += n] = v; p >>= 1;) st[p] = op(st[p << 1], st[(p << 1) | 1]);
  }
  int query(int l, int r) {
    int resl = NEUT, resr = NEUT;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l & 1) resl = op(resl, st[l++]);
      if (r & 1) resr = op(st[--r], resr);
    }
    return op(resl, resr);
  }
};

int n;
vector<int> g[MAXN];

int d[MAXN], sz[MAXN], p[MAXN];
void dfs1(int u) {
  sz[u] = 1;
  for (int v : g[u])
    if (v != p[u]) {
      p[v] = u, d[v] = d[u] + 1;
      dfs1(v);
      sz[u] += sz[v];
    }
}
int curPos, pos[MAXN], head[MAXN];
void hld(int u, int c = -1) {
  if (c == -1) c = u;
  head[u] = c, pos[u] = curPos++;
  int k = -1;
  for (int v : g[u])
    if (v != p[u]) {
      if (k == -1 || sz[v] > sz[k]) k = v;
    }
  if (k != -1) hld(k, c);
  for (int v : g[u])
    if (v != p[u] && v != k) {
      hld(v);
    }
}
void hld_init() {
  p[0] = -1;
  dfs1(0);
  hld(0);
}

int query(int u, int v, STree &st) {
  int res = NEUT;
  while (head[u] != head[v]) {
    if (d[head[u]] < d[head[v]]) swap(u, v);
    res = op(res, st.query(pos[head[u]], pos[u] + 1));
    u = p[head[u]];
  }
  if (d[u] < d[v]) swap(u, v);
  res = op(res, st.query(pos[v], pos[u] + 1));
  return res;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int q;
  cin >> n >> q;
  int v[n];
  forn(i, n) cin >> v[i];
  forn(i, n - 1) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g[a].pb(b);
    g[b].pb(a);
  }
  hld_init();
  int a[n];
  forn(i, n) a[pos[i]] = v[i];
  STree st(n, a);
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int s, x;
      cin >> s >> x;
      s--;
      st.upd(pos[s], x);
    } else {
      int a, b;
      cin >> a >> b;
      a--, b--;
      cout << query(a, b, st) << " ";
    }
  }
  cout << "\n";
  return 0;
}
