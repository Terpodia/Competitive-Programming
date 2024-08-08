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
  int n;
  scanf("%d", &n);

  ll p[n], k[n];
  for (int i = 0; i < n; i++) scanf("%lld%lld", p + i, k + i);

  ll pref[n + 1], suff[n + 1];
  pref[0] = suff[n] = 1;

  for (int i = 1; i <= n; i++)
    pref[i] = (pref[i - 1] * (k[i - 1] + 1LL)) % (MOD - 1);
  for (int i = n - 1; i >= 0; i--)
    suff[i] = (suff[i + 1] * (k[i] + 1LL)) % (MOD - 1);

  ll cnt = 1, sum = 1, prod = 1;

  for (int i = 0; i < n; i++) {
    cnt = (cnt * (k[i] + 1)) % MOD;

    ll num = (binpow(p[i], k[i] + 1) - 1);
    num %= MOD, num += MOD, num %= MOD;
    ll den = inv(p[i] - 1);
    sum *= (num * den) % MOD;
    sum %= MOD;

    ll e = (k[i] * (k[i] + 1LL)) / 2LL;
    e %= (MOD - 1);

    ll add = (pref[i] * suff[i + 1]) % (MOD - 1);
    e = (e * add) % (MOD - 1);

    prod *= binpow(p[i], e);
    prod %= MOD;
  }

  printf("%lld %lld %lld\n", cnt, sum, prod);
  return 0;
}
