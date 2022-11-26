//-Si puedes imaginarlo, puedes programarlo- Alejandro Taboada
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
#define line cout << "\n........................................\n";
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n, k, a[5][1000], b[5][1001], dp[1001];

int solve(int i) {
  int& ret = dp[i];
  if (ret != -1) return ret;
  ret = 0;

  rep(j, 1, n + 1) {
    bool can = true;
    rep(z, 0, k) can &= b[z][j] > b[z][i];
    if (can) ret = max(ret, 1 + solve(j));
  }

  return ret;
}

int main() {
  scanf("%d%d", &n, &k);
  rep(i, 0, k) rep(j, 0, n) scanf("%d", &a[i][j]);
  rep(i, 0, k) rep(j, 0, n) b[i][a[i][j]] = j;

  memset(dp, -1, sizeof(dp));

  int ans = 0;
  rep(i, 1, n + 1) { ans = max(ans, 1 + solve(i)); }

  printf("%d\n", ans);

  return 0;
}
