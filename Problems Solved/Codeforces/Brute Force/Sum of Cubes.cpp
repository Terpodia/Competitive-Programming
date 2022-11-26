#include <math.h>

#include <cstdio>

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    long double x;
    scanf("%Lf", &x);
    bool f = false;

    for (long double a = 1; a < 30000; a++) {
      if (x - (a * a * a) > 0) {
        long double root = cbrt(x - a * a * a);
        long double aux = (long long)root;
        if (root == aux) {
          f = true;
          break;
        }
      }
    }
    if (f)
      printf("YES\n");
    else
      printf("NO\n");
  }

  return 0;
}
