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

const int MAXN = 2e5 + 10;
const int INF = 1e9 + 10;

int n, p[MAXN];
ll a[MAXN];
vector<int> g[MAXN];

ll dfs(int u) {
  ll ret = INF;
  for (int v : g[u])
    if (v != p[u]) {
      ret = min(ret, dfs(v));
    }
  if (ret == INF) return a[u];
  if (ret < a[u]) return ret;

  ll k = (ret - a[u]) / 2;
  return a[u] + k;
}

void solve() {
  cin >> n;
  forn(i, n) cin >> a[i];
  p[0] = -1;
  forn(i, n - 1) {
    cin >> p[i + 1];
    p[i + 1]--;
    g[i + 1].pb(p[i + 1]);
    g[p[i + 1]].pb(i + 1);
  }
  ll lo = INF;
  for (int v : g[0]) lo = min(lo, dfs(v));
  cout << a[0] + lo << "\n";
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
