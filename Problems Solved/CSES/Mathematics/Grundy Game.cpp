#include <bits/stdc++.h>
using namespace std;

int dp[2001];

int solve(int n) {
  int& ret = dp[n];
  if (ret != -1) return ret;
  if (n <= 2) return ret = 0;
  vector<int> v;
  for (int i = 1; i < n; i++) {
    int m1 = i, m2 = n - i;
    if (m1 == m2) continue;
    v.push_back(solve(m1) ^ solve(m2));
  }
  sort(v.begin(), v.end());
  if (v[0] > 0) return ret = 0;
  ret = v.back() + 1;
  for (int i = 0; i < n - 1; i++)
    if (v[i + 1] - v[i] > 1) {
      return ret = v[i] + 1;
    }
  return ret;
}

int main() {
  memset(dp, -1, sizeof(dp));
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    if (n > 2000) {
      puts("first");
      continue;
    }
    int ans = solve(n);
    printf("%s\n", (ans > 0) ? "first" : "second");
  }
  return 0;
}
