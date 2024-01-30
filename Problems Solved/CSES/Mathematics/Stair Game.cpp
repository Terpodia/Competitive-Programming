#include <cstdio>

int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    int p[n];
    for (int i = 0; i < n; i++) scanf("%d", p + i);
    int acc = 0;
    for (int i = 1; i < n; i += 2) acc ^= p[i];
    if (acc > 0)
      puts("first");
    else
      puts("second");
  }
  return 0;
}
