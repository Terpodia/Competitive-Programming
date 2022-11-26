#include <cstdio>
using ll = long long;

const ll MOD = 1e9 + 7;

ll binpow(ll n, ll k) {
  ll ret = 1;

  while (k != 0) {
    if ((k & 1) == 1) ret = (ret * n) % MOD;

    n = (n * n) % MOD;
    k >>= 1;
  }

  return ret;
}

int main() {
  int t;
  scanf("%d", &t);

  while (t--) {
    ll n, k;
    scanf("%lld%lld", &n, &k);
    printf("%lld\n", binpow(n, k));
  }

  return 0;
}
