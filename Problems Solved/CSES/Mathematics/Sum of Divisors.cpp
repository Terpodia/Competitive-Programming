#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;

ll binpow(ll a, ll b) {
  ll res = 1;
  while (b) {
    if (b & 1) res = (res * a) % MOD;
    a = (a * a) % MOD;
    b >>= 1;
  }
  return res;
}

ll inv(ll a) { return binpow(a, MOD - 2); }

int main() {
  ll n;
  scanf("%lld", &n);
  ll ans = 0;
  for (ll i = 1; i * i <= n; i++) {
    ll k = (n - i * i) / i;
    ll lst = i * i + i * k;

    ll p1 = (k + 1) % MOD;
    ll p2 = (lst + i * i) % MOD;
    ll sum = ((p1 * p2) % MOD) * inv(2);
    sum %= MOD;

    ans += (sum * inv(i)) % MOD;
    ans %= MOD;

    if (i * i + i <= n) {
      k = (n - i * i - i) / i + 1;
      k += MOD, k %= MOD;
      ans += (k * i) % MOD;
      ans %= MOD;
    }
  }
  printf("%lld\n", ans);
  return 0;
}
