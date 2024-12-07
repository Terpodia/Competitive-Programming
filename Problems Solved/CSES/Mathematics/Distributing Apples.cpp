#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;

const int MAXN = 2e6 + 10;

ll f[MAXN];

ll binpow(ll a, ll b) {
  ll ret = 1;
  while (b) {
    if (b & 1) ret = (ret * a) % MOD;
    a = (a * a) % MOD;
    b >>= 1;
  }
  return ret;
}
ll inv(ll a) { return binpow(a, MOD - 2); }
ll comb(int n, int k) {
  ll num = f[n];
  ll den = inv((f[k] * f[n - k]) % MOD);
  return (num * den) % MOD;
}

int main() {
  f[0] = 1;
  for (int i = 1; i < MAXN; i++) f[i] = (f[i - 1] * (ll)i) % MOD;
  int n, m;
  scanf("%d%d", &n, &m);
  printf("%lld\n", comb(n + m - 1, n - 1));
  return 0;
}
