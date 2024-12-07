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

const int MAXN = 3000;

int n, m;

vector<pair<int, ll>> g[MAXN];

void solve() {
  ll d[n];
  int p[n];
  forn(i, n) d[i] = 0, p[i] = i;
  forn(_, n) forn(u, n) {
    for (auto [v, w] : g[u]) {
      if (d[v] > d[u] + w) {
        d[v] = d[u] + w;
        p[v] = u;
      }
    }
  }
  forn(u, n) {
    for (auto [v, w] : g[u]) {
      if (d[v] > d[u] + w) {
        p[v] = u;
        cout << "YES\n";
        vector<bool> vis(n, false);
        vector<int> ans;
        while (!vis[v]) {
          vis[v] = true;
          ans.pb(v + 1);
          v = p[v];
        }
        ans.pb(v + 1);
        reverse(all(ans));
        while (ans[0] != ans.back()) ans.pop_back();
        for (int i : ans) cout << i << " ";
        cout << "\n";
        return;
      }
    }
  }
  cout << "NO\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  forn(i, m) {
    int u, v;
    ll w;
    cin >> u >> v >> w;
    u--, v--;
    g[u].pb(make_pair(v, w));
  }
  solve();
  return 0;
}
