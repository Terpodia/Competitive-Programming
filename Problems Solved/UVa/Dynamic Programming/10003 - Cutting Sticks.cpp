#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int l, n, c[60], dp[60][60];

int solve(int i, int j) {
  int& ret = dp[i][j];
  if (ret != -1) return ret;
  if (j - i <= 1) return ret = 0;

  ret = INF;
  int cnt = c[j] - c[i];
  for (int k = i + 1; k < j; k++) {
    ret = min(ret, cnt + solve(i, k) + solve(k, j));
  }
  return ret;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  while (cin >> l && l > 0) {
    cin >> n;
    c[0] = 0;
    for (int i = 1; i <= n; i++) cin >> c[i];
    c[n + 1] = l;
    memset(dp, -1, sizeof(dp));
    cout << "The minimum cutting is " << solve(0, n + 1) << ".\n";
  }
  return 0;
}
