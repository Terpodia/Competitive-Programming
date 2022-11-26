#include <cstdio>
using ll = long long;

ll gcd(ll a, ll b) { return (b == 0) ? a : gcd(b, a % b); }

int main() {
  ll l, r;
  scanf("%lld%lld", &l, &r);

  for (ll a = l; a <= r; a++) {
    for (ll b = a + 1; b <= r; b++) {
      for (ll c = b + 1; c <= r; c++) {
        if (gcd(a, b) == 1 && gcd(b, c) == 1 && gcd(a, c) != 1) {
          printf("%lld %lld %lld\n", a, b, c);
          return 0;
        }
      }
    }
  }

  puts("-1");
  return 0;
}
