// -Si puedes imaginarlo, puedes programarlo- Alejandro Taboada
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define f first
#define s second
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define rep(i, x, n) \
  for (__typeof(n) i = (x); i != (n); i += 1 - 2 * ((x) > (n)))
#define dbg(x) cout << #x << "=" << x << " ";
#define line                                                                 \
  cout << "\n.............................................................." \
          "\n";

typedef pair<int, int> ii;

const int MAXN = 800, INF = 1e9;

int n, dp[MAXN][MAXN];
ii a[MAXN], sz[MAXN][MAXN];

int cnt(ii& a, ii& b) { return a.f * a.s * b.s; }

int main() {
  scanf("%d", &n);
  rep(i, 0, n) scanf("%d%d", &a[i].f, &a[i].s);
  rep(i, 0, n) {
    sz[i][i] = a[i];
    rep(j, i + 1, n) sz[i][j] = {sz[i][j - 1].f, a[j].s};
  }
  memset(dp, 0, sizeof(dp));
  rep(i, 1, n) {
    for (int j = 0; j + i < n; j++) {
      int l = j, r = j + i;
      dp[l][r] = INF;
      rep(k, l, r) {
        dp[l][r] = min(dp[l][r],
                       dp[l][k] + dp[k + 1][r] + cnt(sz[l][k], sz[k + 1][r]));
      }
    }
  }

  printf("%d\n", dp[0][n - 1]);
  return 0;
}

