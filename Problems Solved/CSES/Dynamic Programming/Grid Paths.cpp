#include <cstring>
#include <iostream>
using namespace std;

const int MOD = 1e9 + 7;

void fastIO() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}

int main(void) {
  fastIO();
  int n;
  cin >> n;
  char grid[n][n];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) cin >> grid[i][j];

  long long dp[n][n];
  memset(dp, 0, sizeof(dp));
  (grid[0][0] == '*') ? dp[0][0] = 0 : dp[0][0] = 1;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (grid[i][j] == '*') continue;
      if (i - 1 >= 0) dp[i][j] = dp[i - 1][j];
      if (j - 1 >= 0) dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD;
    }
  }

  cout << dp[n - 1][n - 1] << "\n";

  return 0;
}
