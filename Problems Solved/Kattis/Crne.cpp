#include <cstdio>
int aux;

typedef long long ll;

int main() {
  ll n;
  aux = scanf("%lld", &n);
  if (n == 1)
    puts("2");
  else {
    ll ans = 2;
    n--;
    ll m = (n + 1) / 2;
    ll a1 = 2 * 2;
    ll am = a1 + 2 * (m - 1);

    ans += (m * (am + a1)) / 2;

    if (n % 2 == 1) ans -= am / 2;

    printf("%lld\n", ans);
  }

  return 0;
}
