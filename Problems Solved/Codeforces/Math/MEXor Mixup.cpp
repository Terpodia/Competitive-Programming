#include <cstdio>

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int a, b;
    scanf("%d%d", &a, &b);
    int acc, ans = a, n = a - 1;

    if (n % 4 == 0)
      acc = n;
    else if (n % 4 == 1)
      acc = 1;
    else if (n % 4 == 2)
      acc = n + 1;
    else
      acc = 0;

    if (acc != b) {
      int x = b ^ acc;
      (x != a) ? ans++ : ans += 2;
    }

    printf("%d\n", ans);
  }

  return 0;
}
