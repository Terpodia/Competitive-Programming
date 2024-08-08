#include "bits/stdc++.h"
using namespace std;

const int MAXK = 100;
const int MAXN = 1e6 + 1;

int k;
int p[MAXK], dp[MAXN];

int solve(int i) {
  int& ret = dp[i];
  if (ret != -1) return ret;
  if (i == 0) return ret = 0;
  for (int j = 0; j < k; j++) {
    if (i < p[j]) continue;
    if (solve(i - p[j]) == 0) return ret = 1;
  }
  return ret = 0;
}

int main() {
  int n;
  scanf("%d%d", &n, &k);
  for (int i = 0; i < k; i++) {
    scanf("%d", p + i);
  }
  memset(dp, -1, sizeof(dp));
  for (int i = 1; i <= n; i++) {
    if (dp[i] == -1) solve(i);
    if (dp[i] == 0)
      printf("L");
    else
      printf("W");
  }
  puts("");
  return 0;
}
