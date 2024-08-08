#include "bits/stdc++.h"
using namespace std;

typedef long double ld;

int n, k;

ld dp[101][2];

int lo;

ld solve(int i, int flag) {
  if (i == n) return flag;
  ld& ret = dp[i][flag];
  if (ret >= 0) return ret;

  if (!flag) {
    ret = (ld)(lo - 1) / (ld)k * solve(i + 1, flag);
    ret += solve(i + 1, 1) / (ld)k;
  } else
    ret = (ld)lo / (ld)k * solve(i + 1, flag);
  return ret;
}

int main() {
  scanf("%d%d", &n, &k);
  ld ans = 0;
  for (int i = 1; i <= k; i++) {
    for (int j = 0; j < 101; j++) dp[j][0] = dp[j][1] = -1;
    lo = i;
    ans += solve(0, 0) * (ld)i;
  }
  printf("%.6Lf\n", ans);
  return 0;
}
