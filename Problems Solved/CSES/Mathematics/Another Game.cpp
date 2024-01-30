#include <cstdio>

int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    int x[n];
    for (int i = 0; i < n; i++) scanf("%d", x + i);
    bool win = false;
    for (int i = 0; i < n; i++) {
      if (x[i] & 1) win = true;
    }
    printf("%s\n", (win) ? "first" : "second");
  }
  return 0;
}
