#include <cstdio>

typedef long long ll;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    ll n, k;
    scanf("%lld%lld", &n, &k);
    k--;

    if (n % 2 == 0) {
      printf("%lld\n", k % n + 1);
    } else {
      ll d = n / 2;
      ll ans = k % n;
      ans = (ans + k / d) % n;
      printf("%lld\n", ans + 1);
    }
  }

  return 0;
}
