#include <cstdio>

typedef long long ll;

const int MAXK = 2e5 + 3;
const ll MOD = 1e9 + 7;

ll n, k, p[MAXK], fact[MAXK], x;

ll s(ll a, ll b) { return (((a - b) % MOD) + MOD) % MOD; }

ll binpow(ll a, ll b) {
  a %= MOD;

  ll ret = 1;

  while (b) {
    if (b & 1) ret = (ret * a) % MOD;
    b >>= 1;
    a = (a * a) % MOD;
  }

  return ret;
}

ll comb(ll a, ll b) {
  ll num = fact[a];
  ll den = (fact[b] * fact[s(a, b)]) % MOD;

  return (num * binpow(den, MOD - 2)) % MOD;
}

ll solve(ll b) {
  if (b == 1) return x;

  ll y = x;

  ll ret = (n % 2 == 0) ? binpow(p[n], b - 1) : 0;
  if (n % 2 == 0) y = s(x, 1);

  ret = (ret + (y * solve(b - 1)) % MOD) % MOD;
  return ret;
}

int main() {
  p[0] = fact[0] = fact[1] = 1;

  for (ll i = 1; i < MAXK; i++) p[i] = (p[i - 1] * 2) % MOD;

  for (ll i = 2; i < MAXK; i++) fact[i] = (fact[i - 1] * i) % MOD;

  int t;
  scanf("%d", &t);

  while (t--) {
    scanf("%lld%lld", &n, &k);
    for (int i = 0; i < n; i += 2) x = (x + comb(n, i)) % MOD;

    x = (x + 1) % MOD;

    if (k == 0)
      puts("1");
    else
      printf("%lld\n", solve(k));

    x = 0;
  }

  return 0;
}
