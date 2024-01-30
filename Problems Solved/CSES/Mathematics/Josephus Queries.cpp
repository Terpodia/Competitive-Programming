#include <cstdio>

int f(int n, int k) {
  if (n == 1) return 1;
  if (k <= (n + 1) / 2) {
    return (k <= n / 2) ? 2 * k : 1;
  }
  if (n % 2 == 0) return 2 * f(n / 2, k - (n + 1) / 2) - 1;
  return 2 * f(n / 2, k - (n + 1) / 2) + 1;
}

int main() {
  int q;
  scanf("%d", &q);
  while (q--) {
    int n, k;
    scanf("%d%d", &n, &k);
    printf("%d\n", f(n, k));
  }
  return 0;
}
