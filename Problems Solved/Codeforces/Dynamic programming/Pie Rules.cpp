#include <bits/stdc++.h>
using namespace std;

int n;
int a[53], sum, dp[53][2];

int f(int i, int t) {
  if (i == n) return sum;
  int& ret = dp[i][t];
  if (ret != -1) return ret;
  if (t == 0) {
    return ret = max(f(i + 1, t) - a[i], f(i + 1, 1));
  }
  return ret = min(f(i + 1, t), f(i + 1, 0) - a[i]);
}

int main() {
  memset(dp, -1, sizeof(dp));
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  for (int i = 0; i < n; i++) sum += a[i];

  int res = f(0, 0);

  printf("%d %d\n", sum - res, res);

  return 0;
}
