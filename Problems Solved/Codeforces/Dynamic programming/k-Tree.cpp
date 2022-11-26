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

typedef long long ll;

const ll MOD = 1e9 + 7;

int n, k, d;
ll dp[101][2];

ll solve(int m, int flag) {
  if (m < 0) return 0;
  if (m == 0) return flag;
  ll& ret = dp[m][flag];
  if (ret != -1) return ret;
  ret = 0;
  rep(i, 0, k + 1) {
    ret += solve(m - i, flag | (i >= d));
    ret %= MOD;
  }
  return ret;
}

int main() {
  scanf("%d%d%d", &n, &k, &d);
  memset(dp, -1, sizeof(dp));
  printf("%lld\n", solve(n, 0));
  return 0;
}
