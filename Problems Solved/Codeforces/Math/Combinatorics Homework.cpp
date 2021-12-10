#include <iostream>
#include <algorithm>
using namespace std;

int aux;

int main() {
  int t;
  aux = scanf("%d", &t);
  while (t--) {
    int a, b, c, m;
    aux = scanf("%d%d%d%d", &a, &b, &c, &m);

    if (c < b)
      swap(c, b);
    if (c < a)
      swap(c, a);

    int l = max(c - 1 - (a + b), 0), r = a + b + c - 3;

    (m >= l && m <= r) ? puts("YES") : puts("NO");
  }

  return 0;
}
