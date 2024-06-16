#include <cstdio>

typedef long long ll;

int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    ll l, r;
    scanf("%lld%lld", &l, &r);
    ll x = 2;
    int ans = 0;
    while (x <= r) x *= 2LL, ans++;
    printf("%d\n", ans);
  }
  return 0;
}
