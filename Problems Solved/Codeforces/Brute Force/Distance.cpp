#include <iostream>
using namespace std;
int aux;

int main() {
  int t;
  aux = scanf("%d", &t);
  while (t--) {
    int x, y;
    aux = scanf("%d%d", &x, &y);

    bool can = false;

    for (int i = 0; i <= 300; i++) {
      if (can) break;

      for (int j = 0; j <= 300; j++) {
        if (can) break;

        if (abs(x - i) + abs(y - j) == (abs(x) + abs(y)) / 2 &&
            i + j == (abs(x) + abs(y)) / 2) {
          can = true;
          printf("%d %d\n", i, j);
        }
      }
    }

    if ((abs(x) + abs(y)) % 2 != 0) can = false;

    if (!can) puts("-1 -1");
  }

  return 0;
}
