#include <cstdio>

int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int a, b;
    scanf("%d%d", &a, &b);
    if (a == 0)
      puts("1");
    else
      printf("%d\n", a + 2 * b + 1);
  }
  return 0;
}

