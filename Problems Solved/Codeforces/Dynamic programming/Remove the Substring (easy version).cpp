#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()

const int INF = 1e9;

int n, m;
string s, t;

int dp[201][201];

int solve(int i, int j) {
  if (j == m) return n - i - 1;
  if (i == n - 1) return -INF;
  int& ret = dp[i + 1][j];
  if (ret != -1) return ret;
  ret = -INF;
  for (int k = i + 1; k < n; k++)
    if (s[k] == t[j]) {
      int x = solve(k, j + 1);
      if (x >= 0) ret = max(ret, max(k - i - 1, x));
    }
  return ret;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> s >> t;
  n = sz(s), m = sz(t);
  memset(dp, -1, sizeof(dp));
  cout << solve(-1, 0) << "\n";
  return 0;
}
