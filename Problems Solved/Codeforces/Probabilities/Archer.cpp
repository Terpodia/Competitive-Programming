#include <cstdio>
typedef long double ld;

int main() {
  ld a, b, c, d;
  scanf("%Lf%Lf%Lf%Lf", &a, &b, &c, &d);

  /*
   * P = a/b + (1-a/b)(1-c/d) * P
   * P - P(1-a/b)(1-c/d) = a/b
   * P (1 - (1-a/b)(1-c/d)) = a/b
   * P = a/(b*(1-(1-a/b)(1-c/d))
   */

  printf("%.10Lf\n", a / (b * (1 - (1 - a / b) * (1 - c / d))));

  return 0;
}
