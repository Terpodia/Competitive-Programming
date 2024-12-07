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

const int MAXN = 10000;

vector<int> g[MAXN];

vector<int> color;

int k;

void dfs(int u) {
  vector<bool> can(k, true);
  for (int v : g[u]) {
    if (color[v] != -1) can[color[v]] = false;
  }
  forn(i, k) if (can[i]) color[u] = i;
  for (int v : g[u])
    if (color[v] == -1) {
      dfs(v);
    }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen("kgraph.in", "r", stdin);
  freopen("kgraph.out", "w", stdout);
  int n, m;
  cin >> n >> m;
  forn(i, m) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].pb(v);
    g[v].pb(u);
  }
  forn(i, n) k = max(k, len(g[i]));
  if (k % 2 == 0) k++;
  cout << k << "\n";
  color = vector<int>(n, -1);
  dfs(0);
  for (int i : color) cout << i + 1 << "\n";
  return 0;
}
