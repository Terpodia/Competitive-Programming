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

#define mp make_pair

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

int n;
pair<ll, ll> a[MAXN];
ll ans = 0;

vector<pair<int, ll>> g[MAXN];

ll dist[MAXN];
void dijkstra(int s) {
  fill(dist, dist + n, INF);
  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>>
      pq;
  dist[s] = 0;
  pq.push(mp(0, s));
  while (!pq.empty()) {
    auto [p, u] = pq.top();
    pq.pop();
    if (p != dist[u]) continue;
    for (auto &[v, w] : g[u]) {
      if (p + w < dist[v]) dist[v] = p + w, pq.push(mp(p + w, v));
    }
  }
}

void construct() {
  fore(i, 1, n) { g[i].push_back({i - 1, 0}); }
  forn(i, n) {
    int l = (int)(prev(upper_bound(a + i, a + n,
                                   make_pair(a[i].fst + a[i].snd, INF))) -
                  a);
    if (l > i) g[i].push_back({l, 0});
    if (l + 1 < n)
      g[i].push_back({l + 1, max(0LL, a[l + 1].fst - a[i].fst - a[i].snd)});
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  forn(i, n) { cin >> a[i].fst >> a[i].snd; }
  sort(a, a + n);
  forn(i, n) ans += a[i].snd;
  construct();
  dijkstra(0);
  ans += dist[n - 1];
  cout << ans << "\n";
  return 0;
}
