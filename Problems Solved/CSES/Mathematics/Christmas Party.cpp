#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;

const int MAXN = 1e6 + 1;

ll dp[MAXN];

ll f(ll n) {
  if (n == 0) return 1;
  if (n == 1) return 0;
  ll& ret = dp[n];
  if (ret != -1) return ret;
  return ret = ((ll)(n - 1) * f(n - 1) + (ll)(n - 1) * f(n - 2)) % MOD;
}

int main() {
  int n;
  scanf("%d", &n);
  memset(dp, -1, sizeof(dp));
  printf("%lld\n", f(n));
  return 0;
}
