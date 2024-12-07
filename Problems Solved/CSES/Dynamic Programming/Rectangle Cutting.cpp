#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int a, b;

int dp[510][510];

int solve(int r, int c) {
  int& ret = dp[r][c];
  if (ret != -1) return ret;
  if (r == c) return ret = 0;
  ret = INF;
  for (int i = 1; i < r; i++) {
    ret = min(ret, 1 + solve(i, c) + solve(r - i, c));
  }
  for (int i = 1; i < c; i++) {
    ret = min(ret, 1 + solve(r, i) + solve(r, c - i));
  }
  return ret;
}

int main() {
  scanf("%d%d", &a, &b);
  memset(dp, -1, sizeof(dp));
  printf("%d\n", solve(a, b));
  return 0;
}
