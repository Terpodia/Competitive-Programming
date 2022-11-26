/*
*************************************************************
"Si puedes imaginarlo, puedes programarlo" Alejandro Taboada.
*************************************************************
*/

#include <iostream>
using namespace std;

#define sz(x) (int)x.size()
#define forn(i, x, n) for (int i = (x); i < (int)n; i++)

int main() {
  int t;
  scanf("%d", &t);

  while (t--) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    int s = a + b + c;

    if (s % 9 != 0 || a < s / 9 || b < s / 9 || c < s / 9)
      puts("NO");
    else
      puts("YES");
  }

  return 0;
}
