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

const ll INF = 1e18;

const int MAXN = 3000;

int n, m;
vector<pair<int, ll>> g[MAXN];
bool ok[MAXN], vis[MAXN];

bool check(int u) {
  vis[u] = true;
  bool ret = (u == n - 1);
  for (auto [v, w] : g[u])
    if (!vis[v]) {
      ret |= check(v);
    }
  return ret;
}

void solve() {
  ll d[n];
  forn(i, n) d[i] = -INF;
  d[0] = 0;
  forn(i, n) {
    forn(j, n) vis[j] = false;
    ok[i] = check(i);
  }
  forn(_, n) forn(i, n) if (d[i] != -INF && ok[i]) {
    for (auto [u, w] : g[i]) {
      d[u] = max(d[u], w + d[i]);
    }
  }
  forn(i, n) if (d[i] != -INF && ok[i]) {
    for (auto [u, w] : g[i]) {
      if (d[u] < w + d[i]) {
        cout << "-1\n";
        return;
      }
      d[u] = max(d[u], w + d[i]);
    }
  }
  cout << d[n - 1] << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  forn(i, m) {
    int a, b;
    ll x;
    cin >> a >> b >> x;
    a--, b--;
    g[a].pb(make_pair(b, x));
  }
  solve();
  return 0;
}
