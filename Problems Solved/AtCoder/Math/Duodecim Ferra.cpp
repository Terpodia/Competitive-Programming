#include <cstdio>
#include <cstring>
using ll = long long;

ll dp[201][12];

ll comb(int n, int k) {
  if (k == 0 || n == k) return 1;
  if (k > n) return 0;

  ll& ret = dp[n][k];
  return (ret != -1) ? ret : ret = comb(n - 1, k) + comb(n - 1, k - 1);
}

int main() {
  memset(dp, -1, sizeof(dp));
  int l;
  scanf("%d", &l);
  printf("%lld\n", comb(l - 1, 11));

  return 0;
}
