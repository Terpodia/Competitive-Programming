#include <cstdio>

int main() {
  int n;
  scanf("%d", &n);
  int ans = 1;
  if (n >= 2) ans += (n * (n - 1)) / 2;
  if (n >= 4) ans += (n * (n - 1) * (n - 2) * (n - 3)) / 24;
  printf("%d\n", ans);
  return 0;
}
