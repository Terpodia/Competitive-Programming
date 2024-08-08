#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;

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

int main() {
  ll n;
  scanf("%lld", &n);
  ll ans = 0;
  ans = binpow(2, n * n);
  ans += 2LL * binpow(2, (n * n + 3LL) / 4LL), ans %= MOD;
  ans += binpow(2, (n * n + 1) / 2LL), ans %= MOD;
  ans = (ans * inv(4)) % MOD;
  printf("%lld\n", ans);
  return 0;
}
