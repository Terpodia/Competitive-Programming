#include <cstdio>

int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    printf("%d %d %d\n", (b % 2 == c % 2), (a % 2 == c % 2), (a % 2 == b % 2));
  }
  return 0;
}
