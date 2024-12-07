#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 250000;

const ll MOD = 1e9 + 7;

ll binpow(ll a, ll b) {
  ll ret = 1;
  while (b > 0) {
    if (b & 1) ret = (ret * a) % MOD;
    a = (a * a) % MOD;
    b >>= 1;
  }
  return ret;
}
ll inv(ll x) { return binpow(x, MOD - 2); }

int main() {
  int n;
  scanf("%d", &n);
  vector<ll> dp[2];
  dp[0] = dp[1] = vector<ll>(MAXN * 2, 0);
  dp[1][MAXN] = 1;
  for (int i = n; i >= 1; i--) {
    for (int j = -125260; j <= 125260; j++) {
      dp[0][j + MAXN] = dp[1][j + MAXN + i];
      dp[0][j + MAXN] += dp[1][j + MAXN - i];
      dp[0][j + MAXN] %= MOD;
    }
    swap(dp[0], dp[1]);
  }

  printf("%lld\n", (dp[1][MAXN] * inv(2)) % MOD);
  return 0;
}
