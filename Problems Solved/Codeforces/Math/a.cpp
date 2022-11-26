#include <cstdio>

typedef long long ll;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    ll n;
    scanf("%lld", &n);
    ll ans = 0;

    if (n <= 6) {
      ans += 15;
      printf("%lld\n", ans);
      continue;
    }

    ans += (n / 6) * 15;
    n %= 6;

    if (n > 0 && n <= 4) {
      n += 6, ans -= 15;
      if (n <= 8)
        ans += 20;
      else
        ans += 25;
    }

    else if (n > 0)
      ans += 15;

    printf("%lld\n", ans);
  }

  return 0;
}
