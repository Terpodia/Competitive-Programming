#include <cstdio>
int aux;

typedef long long ll;

const ll MOD = 1e9 + 7;

int main() {
  int t;
  aux = scanf("%d", &t);
  while (t--) {
    ll n, k;
    aux = scanf("%lld%lld", &n, &k);
    ll ans = 0, acc = 1;

    while (k > 0) {
      ans = (ans + (acc * (k % 2))) % MOD;
      acc = (acc * n) % MOD;
      k /= 2;
    }

    printf("%lld\n", ans);
  }

  return 0;
}
