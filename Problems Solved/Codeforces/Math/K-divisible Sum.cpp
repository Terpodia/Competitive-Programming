/*
*************************************************************
"Si puedes imaginarlo, puedes programarlo" Alejandro Taboada.
*************************************************************
*/

#include <iostream>
using namespace std;

#define sz(x) (int)x.size()
#define forn(i, x, n) for (int i = (x); i < (int)n; i++)

void solve() {}

int main() {
  int t;
  scanf("%d", &t);

  while (t--) {
    int n, k;
    scanf("%d%d", &n, &k);
    int m = k - n % k;
    if (n % k == 0) m = 0;
    printf("%d\n", (m + n - 1) / n + 1);
  }

  return 0;
}
