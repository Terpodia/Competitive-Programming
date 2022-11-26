#include <algorithm>
#include <cstdio>
using namespace std;

#define rep(i, x, n) \
  for (__typeof(n) i = (x); i != (n); i += 1 - 2 * ((x) > (n)))

const int INF = 1e9;

int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n, m;
    scanf("%d%d", &n, &m);
    int a[n][m];
    rep(i, 0, n) rep(j, 0, m) scanf("%d", &a[i][j]);

    int dp[2][n + 1][m + 1];

    rep(i, 0, n + 1) dp[0][i][0] = -INF, dp[1][i][0] = INF;
    rep(i, 0, m + 1) dp[0][0][i] = -INF, dp[1][0][i] = INF;
    dp[0][0][1] = dp[0][1][0] = dp[1][0][1] = dp[1][1][0] = 0;

    rep(i, 1, n + 1) rep(j, 1, m + 1) {
      dp[0][i][j] = max(dp[0][i - 1][j], dp[0][i][j - 1]) + a[i - 1][j - 1];
      dp[1][i][j] = min(dp[1][i - 1][j], dp[1][i][j - 1]) + a[i - 1][j - 1];
    }

    if ((n + m - 1) % 2 == 0 && dp[0][n][m] >= 0 && dp[1][n][m] <= 0)
      puts("YES");
    else
      puts("NO");
  }

  return 0;
}
