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
void _scan(long double &x) { aux = scanf("%Lf", &x); }
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

typedef long double ld;

#define sz(x) (int)x.size()

const int INF = 1e9;

int n;
vector<int> a;

int solve(int i, int j) {
  int ret = 0;
  int r, m;
  if (i != j)
    r = (a[j] - a[i]), m = j - i;
  else
    r = 0, m = 1;

  for (int x = i + 1; x < n; x++) {
    if (a[i] * m + r * (x - i) != a[x] * m) ret++;
  }

  for (int x = i - 1; x > -1; x--) {
    if (a[i] * m - r * (i - x) != a[x] * m) ret++;
  }

  return ret;
}

int main() {
  int tc;
  scan(tc);

  while (tc--) {
    scan(n);
    a = vector<int>(n);
    scan(a);

    int ans = INF;

    for (int i = 0; i < n; i++) {
      for (int j = i; j < n; j++) {
        ans = min(ans, solve(i, j));
      }
    }

    printf("%d\n", ans);
  }

  return 0;
}

// "Si puedes imaginarlo puedes programarlo" Alejandro Taboada
