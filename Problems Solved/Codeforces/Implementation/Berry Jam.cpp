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

int n;
vector<int> a, b;

int solve() {
  int sum = 0;
  for (int i = 0; i < n; i++) sum += b[i];

  map<int, int> mp;
  mp[sum] = -1;

  for (int i = 0; i < n; i++) {
    sum -= b[i];
    if (mp.find(sum) == mp.end()) mp[sum] = i;
  }

  int ret = 2 * n;

  sum = 0;
  for (int i = 0; i < n; i++) sum += a[i];

  for (int i = n - 1; i >= 0; i--) {
    if (mp.find(sum * -1) != mp.end()) {
      ret = min(ret, n - 1 - i + mp[sum * -1] + 1);
    }

    sum -= a[i];
  }

  ret = min(ret, n + mp[0] + 1);

  return ret;
}

int main() {
  int tc;
  scan(tc);
  while (tc--) {
    scan(n);
    a = b = vector<int>(n);
    scan(a);
    scan(b);

    for (int i = 0; i < n; i++)
      if (a[i] == 2) a[i] = -1;
    for (int i = 0; i < n; i++)
      if (b[i] == 2) b[i] = -1;

    printf("%d\n", solve());
  }

  return 0;
}

// "Si puedes imaginarlo puedes programarlo" Alejandro Taboada
