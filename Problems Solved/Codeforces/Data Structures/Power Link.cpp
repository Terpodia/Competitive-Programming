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

const int MAXN = 2e5 + 10;

int n, m;
vector<int> g[MAXN], g2[MAXN];
ll a[MAXN];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  forn(i, n) cin >> a[i];
  ll b[n];
  forn(i, n) b[i] = a[i];
  forn(i, m) {
    int c;
    cin >> c;
    forn(j, c) {
      int u;
      cin >> u;
      u--;
      g[u].pb(n + i);
      g[n + i].pb(u);
    }
  }
  int k = (int)ceil(sqrt(n + m));
  forn(i, n + m) {
    for (int v : g[i]) {
      if (len(g[v]) >= k) g2[i].pb(v);
    }
  }
  vector<ll> res(m, 0), cnt(m, 0);
  forn(j, m) {
    int u = j + n;
    ll sum = 0;
    dfor(i, len(g[u])) {
      int v = g[u][i];
      res[j] += a[v] * sum;
      sum += a[v];
    }
    cnt[j] = sum;
  }
  int q;
  cin >> q;
  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int i;
      ll x;
      cin >> i >> x;
      i--;
      if (len(g[i]) < k) {
        ll r = x - a[i];
        for (int v : g[i]) {
          int j = v - n;
          res[j] += (cnt[j] - a[i]) * r;
          cnt[j] += r;
        }
        a[i] = x;
      } else
        b[i] = x;
    } else {
      int j;
      cin >> j;
      j--;
      ll ans = res[j], sum = cnt[j];
      for (int v : g2[j + n]) {
        ll r = b[v] - a[v];
        ans += (sum - a[v]) * r;
        sum += r;
      }
      cout << ans << "\n";
    }
  }
  return 0;
}
