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

const ll INF = 1e18 + 10LL;

const int MAXN = 3e5 + 10;

int n;
vector<ll> a;
vector<int> g[MAXN];

ll dp[MAXN][21];

void dfs(int u, int p = -1) {
  fore(i, 1, 21) dp[u][i] = a[u] * (ll)i;
  for (int v : g[u])
    if (v != p) {
      dfs(v, u);
      ll pref[22], suff[22];

      pref[0] = INF, suff[21] = INF;
      fore(i, 1, 21) pref[i] = min(pref[i - 1], dp[v][i]);
      dfor(i, 21) suff[i] = min(suff[i + 1], dp[v][i]);

      fore(i, 1, 21) { dp[u][i] += min(pref[i - 1], suff[i + 1]); }
    }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    cin >> n;
    a = vector<ll>(n);
    forn(i, n) cin >> a[i];
    forn(i, n - 1) {
      int u, v;
      cin >> u >> v;
      u--, v--;
      g[u].pb(v);
      g[v].pb(u);
    }
    forn(i, n + 1) forn(j, 21) dp[i][j] = -1;

    dfs(0);
    ll res = INF;
    fore(i, 1, 21) res = min(res, dp[0][i]);
    cout << res << "\n";

    forn(i, n) g[i].clear();
  }
  return 0;
}
