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
  ll n, m;
  scanf("%lld%lld", &n, &m);
  ll ans = 0;
  for (ll i = 0; i < n; i++) {
    ans = (ans + binpow(m, __gcd(i, n))) % MOD;
  }
  ans = (ans * inv(n)) % MOD;
  printf("%lld\n", ans);
  return 0;
}
