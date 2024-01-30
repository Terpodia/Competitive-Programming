#include <cstdio>

int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    int x[n];
    for (int i = 0; i < n; i++) {
      scanf("%d", x + i);
      x[i] %= 4;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) ans ^= x[i];
    if (ans > 0)
      puts("first");
    else
      puts("second");
  }
  return 0;
}
