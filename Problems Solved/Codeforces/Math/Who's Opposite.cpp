#include <cmath>
#include <cstdio>

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    int n = abs(b - a) * 2;
    if (a > n || b > n || c > n)
      puts("-1");
    else {
      int ans = (c > n / 2) ? c - n / 2 : c + n / 2;
      printf("%d\n", ans);
    }
  }

  return 0;
}
