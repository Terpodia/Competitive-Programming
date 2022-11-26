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
  int n, m, k;
  scan(n, m, k);
  int sx[k], sy[k], fx[k], fy[k];
  for (int i = 0; i < k; i++) scan(sx[i], sy[i]);
  for (int i = 0; i < k; i++) scan(fx[i], fy[i]);

  string ans;
  for (int i = 0; i < m - 1; i++) ans.push_back('L');
  for (int i = 0; i < n - 1; i++) ans.push_back('U');

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m - 1; j++)
      (i % 2 == 0) ? ans.push_back('R') : ans.push_back('L');
    if (i < n - 1) ans.push_back('D');
  }
  printf("%d\n", (int)ans.size());
  printf("%s\n", ans.c_str());

  return 0;
}

// "Si puedes imaginarlo puedes programarlo" Alejandro Taboada
