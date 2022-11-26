#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 2e5;
const ll MOD = 1e9 + 7;

ll fact[MAXN], cat[MAXN];

ll binpow(ll a, ll b) {
  ll ret = 1;
  while (b > 0) {
    if (b & 1) ret *= a, ret %= MOD;
    a *= a, a %= MOD;
    b >>= 1;
  }
  return ret;
}

ll inv(ll a) { return binpow(a, MOD - 2); }

ll comb(int n, int k) {
  if (k > n) return 0;
  ll num = fact[n];
  ll den = (fact[k] * fact[n - k]) % MOD;
  return (num * inv(den)) % MOD;
}

int main() {
  fact[0] = 1, cat[0] = 1;
  for (ll i = 1; i < MAXN; i++) fact[i] = (i * fact[i - 1]) % MOD;
  for (ll i = 0; i < MAXN - 1; i++) {
    cat[i + 1] = ((4 * i + 2) * inv(i + 2)) % MOD;
    cat[i + 1] *= cat[i], cat[i + 1] %= MOD;
  }
  return 0;
}
