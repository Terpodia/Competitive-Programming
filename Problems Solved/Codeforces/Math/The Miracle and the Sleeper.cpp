/*
*************************************************************
"Si puedes imaginarlo, puedes programarlo" Alejandro Taboada.
*************************************************************
*/

#include <algorithm>
#include <iostream>
using namespace std;

#define sz(x) (int)x.size()
#define forn(i, x, n) for (int i = (x); i < (int)n; i++)

int main() {
  int t;
  scanf("%d", &t);

  while (t--) {
    int l, r;
    scanf("%d%d", &l, &r);
    printf("%d\n", r % (max(l, r / 2 + 1)));
  }

  return 0;
}
