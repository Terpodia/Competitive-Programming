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

const int MAXN = 1e5 + 10;

int n, m, k;

vector<pair<int, ll>> g[MAXN];

struct State {
  ll p;
  int u;
  bool operator<(const State &s) const { return p > s.p; }
};

void solve() {
  vector<ll> dist[n];
  forn(i, n) dist[i] = vector<ll>(k, INF);
  dist[0][0] = 0;
  priority_queue<State> pq;
  pq.push({dist[0][0], 0});
  while (!pq.empty()) {
    auto [cur, u] = pq.top();
    pq.pop();
    bool can = false;
    forn(i, k) if (cur == dist[u][i]) can = true;
    if (!can) continue;
    for (auto [v, w] : g[u]) {
      if (cur + w < dist[v][k - 1]) {
        dist[v][k - 1] = cur + w;
        dfor(j, k - 1) if (dist[v][j] > dist[v][j + 1])
            swap(dist[v][j], dist[v][j + 1]);
        pq.push({cur + w, v});
      }
    }
  }
  for (ll i : dist[n - 1]) cout << i << " ";

  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> k;
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
