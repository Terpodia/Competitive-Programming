#include <cstdio>

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    int dp[n + 1];
    dp[0] = 1, dp[1] = 0;
    for (int i = 2; i < n + 1; i++) dp[i] = (i - 1) * (dp[i - 1] + dp[i - 2]);
    int f = 1;
    for (int i = 2; i < n + 1; i++) f *= i;
    printf("%d/%d\n", dp[n], f);
  }
  return 0;
}
