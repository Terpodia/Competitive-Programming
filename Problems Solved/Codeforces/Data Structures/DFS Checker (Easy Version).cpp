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

const int MAXN = 1e5;

int n;
int parent[MAXN], p[MAXN], pos[MAXN], lo[MAXN], hi[MAXN], sz[MAXN];
bool can[MAXN];
vector<int> g[MAXN];

void dfs(int u) {
  sz[u] = 1, hi[u] = pos[u], lo[u] = pos[u];
  for (int v : g[u]) {
    dfs(v);
    can[u] &= can[v];

    sz[u] += sz[v];
    hi[u] = max(hi[u], hi[v]);
    lo[u] = min(lo[u], lo[v]);
  }
  can[u] &= lo[u] == pos[u];
  can[u] &= hi[u] == pos[u] + sz[u] - 1;
}

void update(int u) {
  if (u == -1) return;
  hi[u] = pos[u], lo[u] = pos[u], can[u] = true;
  for (int v : g[u]) {
    can[u] &= can[v];
    hi[u] = max(hi[u], hi[v]);
    lo[u] = min(lo[u], lo[v]);
  }
  can[u] &= lo[u] == pos[u];
  can[u] &= hi[u] == pos[u] + sz[u] - 1;
  update(parent[u]);
}

void solve() {
  int q;
  cin >> n >> q;
  parent[0] = -1;
  forn(i, n - 1) {
    cin >> parent[i + 1];
    parent[i + 1]--;
    g[parent[i + 1]].pb(i + 1);
  }
  forn(i, n) {
    cin >> p[i];
    p[i]--;
    pos[p[i]] = i;
    can[i] = true;
  }
  dfs(0);
  while (q--) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    swap(pos[p[x]], pos[p[y]]);
    swap(p[x], p[y]);

    update(p[x]);
    update(p[y]);

    if (can[0])
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  forn(i, n) g[i].clear();
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}
