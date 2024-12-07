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

const ll INF = 1e18, MOD = 1e9 + 7;

const int MAXN = 1e5 + 10;

int n, m;

vector<pair<int, ll>> g[MAXN];
vector<int> p[MAXN];
ll cnt[MAXN], dp1[MAXN], dp2[MAXN];

struct State {
  ll p;
  int u;
  bool operator<(const State &s) const { return p > s.p; }
};

ll f1(int u) {
  ll &ret = cnt[u];
  if (ret != -1) return ret;
  if (u == 0) return ret = 1;
  ret = 0;
  for (int v : p[u]) {
    ret += f1(v);
    ret %= MOD;
  }
  return ret;
}

ll f2(int u) {
  ll &ret = dp1[u];
  if (ret != -1) return ret;
  if (u == 0) return 0;
  ret = INF;
  for (int v : p[u]) {
    ret = min(ret, 1LL + f2(v));
  }
  return ret;
}

ll f3(int u) {
  ll &ret = dp2[u];
  if (ret != -1) return ret;
  if (u == 0) return 0;
  ret = -INF;
  for (int v : p[u]) {
    ret = max(ret, 1LL + f3(v));
  }
  return ret;
}

void solve() {
  ll dist[n];
  forn(i, n) dist[i] = INF;
  dist[0] = 0;
  priority_queue<State> pq;
  pq.push({0, 0});
  while (!pq.empty()) {
    auto [cur, u] = pq.top();
    pq.pop();
    if (cur != dist[u]) continue;
    for (auto [v, w] : g[u]) {
      if (cur + w < dist[v]) {
        dist[v] = cur + w;
        pq.push({cur + w, v});
        p[v].clear();
        p[v].pb(u);
      } else if (cur + w == dist[v]) {
        p[v].pb(u);
      }
    }
  }
  cout << dist[n - 1] << " ";
  memset(cnt, -1, sizeof(cnt));
  memset(dp1, -1, sizeof(dp1));
  memset(dp2, -1, sizeof(dp2));
  cout << f1(n - 1) << " " << f2(n - 1) << " " << f3(n - 1);
  cout << "\n";
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
