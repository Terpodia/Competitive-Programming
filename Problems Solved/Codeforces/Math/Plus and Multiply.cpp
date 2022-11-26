#include <cstdio>
using ll = long long;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    ll n, a, b;
    scanf("%lld%lld%lld", &n, &a, &b);

    ll p = 1;
    bool can = false;

    while (true) {
      if (p > n) break;
      if ((n - p) % b == 0) {
        can = true;
        break;
      }
      p *= a;
      if (p == 1) break;
    }

    (!can) ? puts("No") : puts("Yes");
  }

  return 0;
}
