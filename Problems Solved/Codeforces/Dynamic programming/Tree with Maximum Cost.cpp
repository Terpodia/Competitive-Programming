// -Si puedes imaginarlo, puedes programarlo- Alejandro Taboada
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define fst first
#define snd second
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define rep(i, x, n) \
  for (__typeof(n) i = (x); i != (n); i += 1 - 2 * ((x) > (n)))
#define dbg(x) cout << #x << "=" << x << " ";
#define line                                                                 \
  cout << "\n.............................................................." \
          "\n";

const int MAXN = 2e5;

typedef long long ll;

int n;
ll res, a[MAXN], sum[MAXN], ans[MAXN];
vector<int> g[MAXN];

void dfs(int u, int p = -1, int h = 0) {
  sum[u] = a[u];

  for (int v : g[u])
    if (v != p) {
      res += (ll)(h + 1) * a[v];
      dfs(v, u, h + 1);
      sum[u] += sum[v];
    }
}

void go(int u, int p = -1) {
  ans[u] = res;
  for (int v : g[u])
    if (v != p) {
      res -= sum[v];
      sum[u] -= sum[v];
      res += sum[u];
      sum[v] += sum[u];

      go(v, u);

      sum[v] -= sum[u];
      res -= sum[u];
      sum[u] += sum[v];
      res += sum[v];
    }
}

int main() {
  scanf("%d", &n);
  rep(i, 0, n) scanf("%lld", a + i);
  rep(i, 0, n - 1) {
    int u, v;
    scanf("%d%d", &u, &v);
    u--, v--;
    g[u].pb(v);
    g[v].pb(u);
  }
  dfs(0);
  go(0);
  printf("%lld\n", *max_element(ans, ans + n));
  return 0;
}
