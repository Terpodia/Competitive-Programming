#include <cstdio>
using ll = long long;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    ll n;
    scanf("%lld", &n);
    int cnt = 0;
    ll ans = 0, po = 1;
    int m = __builtin_popcountll(n);

    while (cnt < m) {
      if ((n & po) != 0) cnt++;
      if (cnt >= m) break;
      ans += po;
      po <<= 1LL;
    }

    printf("%lld\n", ans);
  }

  return 0;
}
