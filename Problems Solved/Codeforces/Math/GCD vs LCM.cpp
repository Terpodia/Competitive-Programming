#include <cstdio>

int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    int a, b, c, d;
    b = c = d = 1;
    a = n - 3;
    printf("%d %d %d %d\n", a, b, c, d);
  }
  return 0;
}
