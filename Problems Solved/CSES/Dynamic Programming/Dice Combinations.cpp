#include <cstring>
#include <iostream>
using namespace std;

const int MOD = 1e9 + 7;

int main(void) {
  int n;
  scanf("%d", &n);
  int dp[n + 1];
  memset(dp, 0, sizeof(dp));
  dp[0] = 1;

  for (int s = 1; s <= n; s++) {
    for (int i = 1; i <= 6; i++) {
      int x = s - i;
      if (x < 0) continue;
      dp[s] = (dp[s] + dp[x]) % MOD;
    }
  }

  printf("%d\n", dp[n]);

  return 0;
}
