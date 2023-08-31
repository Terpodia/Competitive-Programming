#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// ordered_set<int> x; x.find_by_order(y); x.order_of_key(y)

#define fst first
#define snd second
#define pb push_back
#define mp make_pair
#define SZ(x) (int)x.size()
#define fore(i, x, n) for (auto i = (x); i < (n); i++)
#define all(x) x.begin(), x.end()
#define dbg(x) cerr << #x << "=" << x << " "
#define raya \
  cerr << "\n-----------------------------------------------------------\n"
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// shuffle(.begin(),.end(),rng); uniform_int_distribution<int>(a,b)(rng) [a,b]
typedef long long ll;
typedef long double ld;

const int MAXN = 2e5 + 10;

int n, m, in[MAXN];
ll k, h[MAXN];
vector<int> g[MAXN];
set<pair<ll, int>> st;
ll d[MAXN];

void bfs() {
  fore(i, 0, n) if (!in[i]) { st.insert(mp(h[i], i)); }
  ll cur = 0, cnt = 0;
  while (SZ(st)) {
    auto it = st.lower_bound(mp(cur, -1));
    if (it != st.end()) {
      int u = it->snd;
      d[u] = cnt;
      for (int v : g[u]) {
        if (--in[v] == 0) st.insert(mp(h[v], v));
      }
      cur = it->fst;
      st.erase(it);
    } else
      cnt++, cur = 0;
  }
  fore(i, 0, n) st.insert(mp(k * d[i] + h[i], i));
}

void dfs(int u) {
  for (int v : g[u]) {
    ll cnt = d[u];
    if (h[u] > h[v]) cnt++;
    if (cnt > d[v]) {
      st.erase(mp(d[v] * k + h[v], v));
      d[v] = cnt;
      st.insert(mp(d[v] * k + h[v], v));
      dfs(v);
    }
  }
}

void solve() {
  vector<pair<ll, int>> x;
  fore(u, 0, n) for (int v : g[u]) in[v]++;
  fore(i, 0, n) if (!in[i]) { x.pb(mp(h[i], i)); }
  sort(all(x));
  bfs();
  ll lo = st.begin()->fst, hi = st.rbegin()->fst;
  ll ans = hi - lo;
  fore(i, 0, SZ(x)) {
    auto it = st.find(mp(x[i].fst, x[i].snd));
    st.erase(it);
    st.insert(mp(k + x[i].fst, x[i].snd));
    d[x[i].snd] = 1;
    dfs(x[i].snd);

    lo = st.begin()->fst, hi = st.rbegin()->fst;
    ans = min(ans, hi - lo);
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    cin >> n >> m >> k;
    fore(i, 0, n) cin >> h[i];
    fore(i, 0, m) {
      int u, v;
      cin >> u >> v;
      u--, v--;
      g[u].pb(v);
    }
    solve();
    fore(i, 0, n) g[i].clear();
    fore(i, 0, n) d[i] = 0, in[i] = 0;
    st.clear();
  }
  return 0;
}
