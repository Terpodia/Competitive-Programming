#include <cstdio>

typedef long long ll;

int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    ll n, k;
    scanf("%lld%lld", &n, &k);
    if (n < k)
      puts("NO");
    else if (n == k) {
      printf("YES\n1\n1\n");
    } else if (2 * k <= n + 1) {
      printf("YES\n2\n%lld 1\n", n - k + 1);
    } else
      puts("NO");
  }
  return 0;
}
