#include <cstdio>
#include <cstring>

int solve(int n, int m) {
  int dp[n + 1][m + 1];
  memset(dp, 0, sizeof(dp));
  dp[1][1] = 1;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (dp[i][j] == 1) continue;
      dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
    }
  }
  return dp[n][m];
}

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  printf("%d\n", solve(n, m));

  return 0;
}
