#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
/* ================================================= */
void fastIO() { cin.tie(0)->sync_with_stdio(0); }

int aux;
void _scan(int &x) { aux = scanf("%d", &x); }
void _scan(long long &x) { aux = scanf("%lld", &x); }
void _scan(double &x) { aux = scanf("%lf", &x); }
void _scan(char &x) { aux = scanf(" %c", &x); }
void _scan(char *x) { aux = scanf("%s", x); }
template <typename T>
void _scan(vector<T> &v) {
  for (int i = 0; i < (int)v.size(); i++) _scan(v[i]);
}
void scan() {}
template <typename T, typename... U>
void scan(T &head, U &...tail) {
  _scan(head);
  scan(tail...);
}
/* ================================================= */

#define sz(x) (int)x.size()

int main() {
  int tc;
  scan(tc);

  while (tc--) {
    int n, m, rb, cb, rd, cd;
    scan(n, m, rb, cb, rd, cd);

    int i = rb, j = cb;
    int dr = 1, dc = 1;

    int t = 0;

    while (true) {
      if (i == rd || j == cd) break;
      if (i + dr > n || i + dr < 1) dr *= -1;
      if (j + dc > m || j + dc < 1) dc *= -1;

      i += dr, j += dc;

      t++;
    }

    printf("%d\n", t);
  }

  return 0;
}

// "Si puedes imaginarlo puedes programarlo" Alejandro Taboada
