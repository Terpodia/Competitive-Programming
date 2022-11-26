#include <cmath>
#include <iostream>
using ll = long long;

int main() {
  ll N;
  scanf("%lld", &N);

  N *= 2;

  ll m = sqrt(N), ans = 0;

  for (ll i = 1; i <= m; i++) {
    if (N % i == 0) {
      ll j = N / i;

      if ((N / i - i + 1) % 2 == 0) ans++;
      if ((N / j - j + 1) % 2 == 0) ans++;
    }
  }

  if (m * m == N) ans--;

  printf("%lld\n", ans);

  return 0;
}
