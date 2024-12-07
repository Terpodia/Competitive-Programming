#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
ll a[5010], dp[5010][5010][2];

ll solve(int l, int r, int turn) {
  if (l > r) return 0;
  ll& ret = dp[l][r][turn];
  if (ret != -1) return ret;
  if (turn == 0) {
    ret = a[l] + solve(l + 1, r, 1);
    ret = max(ret, a[r] + solve(l, r - 1, 1));
  } else {
    ret = solve(l + 1, r, 0);
    ret = min(ret, solve(l, r - 1, 0));
  }
  return ret;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
  memset(dp, -1, sizeof(dp));
  printf("%lld\n", solve(0, n - 1, 0));
  return 0;
}
