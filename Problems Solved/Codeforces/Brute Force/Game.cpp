#include <cstdio>

int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    int l = 0, r = n - 1;
    for (int i = 1; i < n; i++) {
      if (!a[i]) break;
      l = i;
    }
    for (int i = n - 2; i >= 0; i--) {
      if (!a[i]) break;
      r = i;
    }
    if (l == n - 1)
      puts("0");
    else
      printf("%d\n", r - l);
  }
  return 0;
}
