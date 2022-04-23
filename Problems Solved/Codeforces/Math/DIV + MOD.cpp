#include <cstdio>

typedef long long ll;

ll f(ll x, ll a) { return (x / a) + (x % a); }

int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    ll l, r, a;
    scanf("%lld%lld%lld", &l, &r, &a);
    if (a - 1 >= r)
      printf("%lld\n", r);
    else {
      ll d = (r - a + 1) / a;
      if (a - 1 + a * d >= l)
        printf("%lld\n", f(a - 1 + a * d, a));
      else
        printf("%lld\n", f(r, a));
    }
  }
  return 0;
}

