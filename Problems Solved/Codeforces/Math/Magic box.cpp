#include <cstdio>

int main() {
  int x, y, z;
  scanf("%d%d%d", &x, &y, &z);
  int x1, y1, z1;
  scanf("%d%d%d", &x1, &y1, &z1);
  int a1, a2, a3, a4, a5, a6;
  scanf("%d%d%d%d%d%d", &a1, &a2, &a3, &a4, &a5, &a6);

  int s = 0;

  if (y < 0) s += a1;
  if (y > y1) s += a2;
  if (z < 0) s += a3;
  if (z > z1) s += a4;
  if (x < 0) s += a5;
  if (x > x1) s += a6;

  printf("%d\n", s);

  return 0;
}
