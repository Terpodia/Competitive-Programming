#include <cmath>
#include <cstdio>

int r1, c1, r2, c2;

bool case1() { return (r1 == r2 && c1 == c2); }

bool case2() {
  return (r1 + c1 == r2 + c2 || r1 - c1 == r2 - c2 ||
          abs(r1 - r2) + abs(c1 - c2) <= 3);
}

bool case3() {
  bool ret = false;

  /*
   * p+q = r1 + c1 y p-q = r2 - c2
   * p = r1 + c1 - q
   * r1 + c1 - q - q = r2 - c2
   * -2q = r2 - c2 - r1 - c1
   *  2q = c2 + r1 + c1 - r2
   *
   * p-q = r1 - c1 y p+q = r2 + c2
   * p = r1 - c1 + q
   * r1 - c1 + q + q = r2 + c2
   * r1 - c1 + 2q = r2 + c2
   * 2q = r2 + c2 - r1 + c1
   */

  ret |= ((r1 + c1 + c2 - r2) % 2 == 0);
  ret |= ((r2 + c2 + c1 - r1) % 2 == 0);

  for (int i = -3; i <= 3; i++) {
    for (int j = -3; j <= 3; j++) {
      int p = r1 + i, q = c1 + j;
      if (abs(p - r1) + abs(q - c1) <= 3) {
        ret |= (p + q == r2 + c2 || p - q == r2 - c2 ||
                abs(p - r2) + abs(q - c2) <= 3);
      }
    }
  }

  return ret;
}

int main() {
  scanf("%d%d%d%d", &r1, &c1, &r2, &c2);

  if (case1())
    puts("0");
  else if (case2())
    puts("1");
  else if (case3())
    puts("2");
  else
    puts("3");

  return 0;
}
