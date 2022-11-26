#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int main(void) {
  int n, x = 0;
  scanf("%d", &n);
  int c[n];
  for (int i = 0; i < n; i++) scanf("%d", c + i);
  for (int i = 0; i < n; i++) x += c[i];

  bool dp[n + 1][x + 1];
  memset(dp, false, sizeof(dp));
  dp[0][0] = true;

  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= x; j++) {
      int r = j - c[i - 1];
      if (r >= 0) dp[i][j] = dp[i - 1][r];
      if (!dp[i][j]) dp[i][j] = dp[i - 1][j];
    }
  }

  int k = 0;
  vector<int> v;

  for (int i = 1; i <= x; i++) {
    if (dp[n][i]) {
      k++;
      v.push_back(i);
    }
  }

  printf("%d\n", k);
  for (int i = 0; i < k; i++) printf("%d ", v[i]);
  puts("");

  return 0;
}
