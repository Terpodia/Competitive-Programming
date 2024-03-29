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

const int MAXN = 1e5 + 10;

int n, k, m, cur;
vector<int> g[MAXN];

int dfs(int u, int p, int& cnt) {
  int acc = 1;
  for (int v : g[u])
    if (v != p) {
      int c = dfs(v, u, cnt);
      if (c >= m && cur - c >= m)
        cnt++, cur -= c;
      else
        acc += c;
    }
  return acc;
}

void solve() {
  int l = 1, r = n;
  while (r > l) {
    int mid = l + (r - l + 1) / 2;
    int cnt = 0;
    m = mid, cur = n;
    dfs(0, -1, cnt);
    if (cnt >= k)
      l = mid;
    else
      r = mid - 1;
  }
  cout << l << "\n";
}

int main() {
  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    cin >> n >> k;
    fore(i, 0, n - 1) {
      int u, v;
      cin >> u >> v;
      u--, v--;
      g[u].pb(v);
      g[v].pb(u);
    }
    solve();
    fore(i, 0, n) g[i].clear();
  }
  return 0;
}
