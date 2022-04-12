#include <cstdio>

typedef long long ll;

const ll MOD = 998244353;

int main() {
  ll f[1001];
  f[0] = 1;
  for (int i = 1; i < 1001; i++) f[i] = (f[i - 1] * i) % MOD;
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    ll n;
    scanf("%lld", &n);
    if (n % 2)
      puts("0");
    else
      printf("%lld\n", (f[n / 2] * f[n / 2]) % MOD);
  }
  return 0;
}

