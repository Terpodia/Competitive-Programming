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

bool solve(int l1, int l2, int l3) {
  if (l2 == l3 && l1 % 2 == 0) return true;
  if (l1 > l3 && l1 - l3 == l2) return true;
  if (l1 > l2 && l1 - l2 == l3) return true;
  return false;
}

int main() {
  int tc;
  scan(tc);
  while (tc--) {
    int l1, l2, l3;
    scan(l1, l2, l3);

    if (solve(l1, l2, l3) || solve(l2, l1, l3) || solve(l3, l1, l2))
      puts("YES");
    else
      puts("NO");
  }

  return 0;
}

// "Si puedes imaginarlo puedes programarlo" Alejandro Taboada
