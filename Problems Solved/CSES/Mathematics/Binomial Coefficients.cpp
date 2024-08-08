#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

const int MAXN = 1e6 + 10;
const ll MOD = 1e9 + 7;

ll fact[MAXN];

ll binpow(ll x, ll y) {
  ll res = 1;
  while (y) {
    if (y & 1) res = (res * x) % MOD;
    x = (x * x) % MOD;
    y >>= 1;
  }
  return res;
}

ll comb(int a, int b) {
  ll num = fact[a];
  ll den = (fact[b] * fact[a - b]) % MOD;
  return (num * binpow(den, MOD - 2)) % MOD;
}

int main() {
  fact[0] = 1;
  for (int i = 1; i < MAXN; i++) fact[i] = (fact[i - 1] * (ll)i) % MOD;
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%lld\n", comb(a, b));
  }
  return 0;
}
