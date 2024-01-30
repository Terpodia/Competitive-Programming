#include <cstdio>

int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
      int x;
      scanf("%d", &x);
      ans ^= x;
    }
    if (ans > 0)
      puts("first");
    else
      puts("second");
  }
  return 0;
}
