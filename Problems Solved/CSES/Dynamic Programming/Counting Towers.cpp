#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;

const int MAXN = 1e6 + 10;

int n;
ll dp[MAXN][3];

int main() {
  dp[0][1] = 2, dp[0][2] = 1;
  for (int i = 1; i < MAXN; i++) {
    for (int flag = 0; flag < 3; flag++) {
      dp[i][flag] = 0;
      if (flag == 0)
        dp[i][flag] = dp[i - 1][1];
      else {
        dp[i][flag] = dp[i][0];
        if (flag == 1) dp[i][flag] = (dp[i][flag] * 2) % MOD;
        dp[i][flag] += dp[i - 1][flag] + 2 * dp[i - 1][2];
        dp[i][flag] %= MOD;
      }
    }
  }
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    scanf("%d", &n);
    printf("%lld\n", dp[n][0]);
  }
  return 0;
}
