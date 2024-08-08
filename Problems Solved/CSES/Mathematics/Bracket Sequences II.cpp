#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

const int MAXN = 1e6 + 10;

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

ll f[MAXN];

ll comb(ll n, ll k) {
  ll num = f[n];
  ll den = (f[k] * f[n - k]) % MOD;
  return (num * inv(den)) % MOD;
}

int main() {
  f[0] = 1;
  for (int i = 1; i < MAXN; i++) f[i] = (f[i - 1] * (ll)i) % MOD;

  int n;
  scanf("%d", &n);
  char s[MAXN];
  scanf("%s", s);
  int m = strlen(s);

  int k = 0;
  for (int i = 0; i < m; i++) {
    k += (s[i] == '(') ? 1 : -1;
    if (k < 0) {
      printf("0\n");
      return 0;
    }
  }
  n -= m;
  if (k > n || (n - k) % 2 != 0) {
    printf("0\n");
    return 0;
  }
  n -= k;
  n /= 2;
  if (n == 0) {
    printf("1\n");
    return 0;
  }
  ll ans = comb(2 * n + k, n);
  ans -= comb(2 * n + k, n - 1);
  ans %= MOD, ans += MOD, ans %= MOD;
  printf("%lld\n", ans);
  return 0;
}
