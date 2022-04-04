#include <algorithm>
#include <bitset>
#include <chrono>
#include <cmath>
#include <cstring>
#include <deque>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <tuple>
#include <vector>

using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void set_IO() {
  cin.tie(0)->sync_with_stdio(0);
  cout << fixed << setprecision(15);
}

void _dbg(istream_iterator<string> it) {}
template <typename T, typename... Args>
void _dbg(istream_iterator<string> it, T& a, Args&... args) {
  cout << *it << "=" << a << " ";
  _dbg(++it, args...);
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define f first
#define s second
#define sz(x) (int)x.size()
#define rep(i, x, n) \
  for (__typeof(n) i = (x); i != (n); i += 1 - 2 * ((x) > (n)))
#define line cout << "\n-----------------------------\n";
#define dbg(args...)                         \
  {                                          \
    string _s = #args;                       \
    replace(_s.begin(), _s.end(), ',', ' '); \
    stringstream _ss(_s);                    \
    istream_iterator<string> _it(_ss);       \
    _dbg(_it, args);                         \
  }

typedef __uint128_t u128;
typedef long long ll;

const int MAXN = 1e5 + 7;

int N, M, inDeg[MAXN];
ll F[MAXN];
vector<int> g[MAXN][2], CC[MAXN];
bool vis[MAXN];
multiset<ll> U[MAXN];

void dfs(int u, int flag) {
  vis[u] = true;
  if (flag == 1) CC[M].push_back(u);
  for (int v : g[u][flag])
    if (!vis[v]) {
      dfs(v, flag);
    }
}

ll calc(vector<int>& cc) {
  queue<pair<int, ll>> Q;
  for (int v : cc)
    if (!inDeg[v]) Q.push({v, F[v]});
  ll ret = 0;
  while (!Q.empty()) {
    auto [u, w] = Q.front();
    Q.pop();
    if (sz(g[u][0]) == 0) {
      ret += w;
      continue;
    }
    int v = g[u][0][0];
    inDeg[v]--;
    U[v].insert(w);
    if (!inDeg[v]) {
      Q.push({v, max(F[v], *U[v].begin())});
      for (auto it = U[v].begin(); it != U[v].end(); it++) {
        if (it == U[v].begin()) continue;
        ret += *it;
      }
    }
  }
  return ret;
}

void solve() {
  memset(vis, false, sizeof(vis));
  rep(i, 0, N) {
    if (!vis[i]) {
      dfs(i, 1);
      M++;
    }
  }
  ll ans = 0;
  rep(i, 0, M) ans += calc(CC[i]);
  cout << ans << "\n";
}

int main() {
  set_IO();
  int tt;
  cin >> tt;
  rep(_, 1, tt + 1) {
    cin >> N;
    M = 0;
    rep(i, 0, N) cin >> F[i];
    memset(inDeg, 0, sizeof(inDeg));
    rep(u, 0, N) {
      int p;
      cin >> p;
      p--;
      if (p < 0) continue;
      g[u][0].push_back(p);
      g[u][1].push_back(p);
      g[p][1].push_back(u);
      inDeg[p]++;
    }
    cout << "Case #" << _ << ": ";
    solve();
    rep(i, 0, N) {
      U[i].clear();
      g[i][0].clear();
      g[i][1].clear();
    }
    rep(i, 0, M) CC[i].clear();
  }
  return 0 - 0;
}
// "Si puedes imaginarlo puedes programarlo" Alejandro Taboada
