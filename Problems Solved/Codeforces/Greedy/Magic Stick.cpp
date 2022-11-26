#include <cstdio>

int aux;

int main() {
  int t;
  aux = scanf("%d", &t);
  while (t--) {
    int x, y;
    aux = scanf("%d%d", &x, &y);

    if (x >= y)
      puts("YES");
    else {
      if (x == 1)
        puts("NO");
      else if (x == 2)
        (y == 3) ? puts("YES") : puts("NO");
      else
        (x == 3) ? puts("NO") : puts("YES");
    }
  }

  return 0;
}
