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

vector<pair<int, int>> queries;

struct STree {
  int n;
  vector<int> st;
  vector<int> lazy;

  STree() { n = 0; }

  STree(int _n) {
    n = _n;
    st = vector<int>(4 * n, 0);
    lazy = vector<int>(4 * n, 0);
    build(1, 0, n);
  }
  void build(int k, int s, int e) {
    if (s + 1 == e) {
      st[k] = 1;
      return;
    }
    int m = (s + e) / 2;
    build(2 * k, s, m);
    build(2 * k + 1, m, e);
    st[k] = st[2 * k] + st[2 * k + 1];
  }
  void push(int k, int s, int e) {
    if (!lazy[k]) return;

    if (lazy[k] == 1)
      st[k] = 0;
    else if (lazy[k] == 2)
      st[k] = e - s;

    if (s + 1 < e) {
      lazy[2 * k] = lazy[k];
      lazy[2 * k + 1] = lazy[k];
    }
    lazy[k] = 0;
  }
  void upd(int k, int s, int e, int a, int b) {
    push(k, s, e);

    if (s >= b || e <= a) return;
    if (s >= a && e <= b) {
      lazy[k] = 1;
      push(k, s, e);
      return;
    }
    int m = (s + e) / 2;
    upd(2 * k, s, m, a, b);
    upd(2 * k + 1, m, e, a, b);
    st[k] = st[2 * k] + st[2 * k + 1];
  }
  void upd() {
    sort(all(queries));
    if (queries[0].fst > 0) upd(1, 0, n, 0, queries[0].fst);
    fore(i, 1, len(queries)) {
      if (queries[i - 1].snd < queries[i].fst)
        upd(1, 0, n, queries[i - 1].snd, queries[i].fst);
    }
    if (queries.back().snd < n) upd(1, 0, n, queries.back().snd, n);
  }
  void init() {
    lazy[1] = 2;
    push(1, 0, n);
  }
  int query() {
    push(1, 0, n);
    return st[1];
  }
};

const int MAXN = 1e5 + 10;

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
    if (v != p[u] && v != k) hld(v);
}

void hld_init() {
  p[0] = -1, d[0] = 0, curPos = 0;
  dfs1(0);
  hld(0);
}

STree st;

void query(int u, int v) {
  queries.clear();
  while (head[u] != head[v]) {
    if (d[head[u]] < d[head[v]]) swap(u, v);
    queries.pb(make_pair(pos[head[u]], pos[u] + 1));
    u = p[head[u]];
  }
  if (d[u] < d[v]) swap(u, v);
  queries.pb(make_pair(pos[v], pos[u] + 1));
  st.upd();
}

void solve() {
  int k;
  cin >> k;
  forn(i, k) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    query(u, v);
  }
  cout << st.query() << "\n";
  st.init();
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  int _ = 1;
  while (tt--) {
    cin >> n;
    forn(i, n - 1) {
      int u, v;
      cin >> u >> v;
      u--, v--;
      g[u].pb(v);
      g[v].pb(u);
    }
    hld_init();
    st = STree(n);
    cout << "Case " << _++ << ":\n";
    int q;
    cin >> q;
    while (q--) {
      solve();
    }
    forn(i, n) g[i].clear();
  }
  return 0;
}
