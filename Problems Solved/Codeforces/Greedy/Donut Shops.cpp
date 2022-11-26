#include <cstdio>

typedef long long ll;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    ll a, b, c;
    scanf("%lld%lld%lld", &a, &b, &c);
    printf("%d ", (a < c) ? 1 : -1);
    printf("%lld\n", (c < b * a) ? b : -1);
  }

  return 0;
}
