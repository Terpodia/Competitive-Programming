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
  int TC;
  scan(TC);

  while (TC--) {
    int n;
    scan(n);
    vector<int> g[n];
    for (int i = 0; i < n; i++) {
      int k;
      scan(k);
      for (int j = 0; j < k; j++) {
        int v;
        scan(v);
        g[i].push_back(v - 1);
      }
    }

    bool ok[n][2];
    memset(ok, false, sizeof(ok));

    for (int i = 0; i < n; i++) {
      for (int j : g[i]) {
        if (!ok[j][1]) {
          ok[j][1] = true;
          ok[i][0] = true;
          break;
        }
      }
    }

    bool op = true;
    for (int i = 0; i < n; i++) op &= ok[i][0];

    if (op)
      puts("OPTIMAL");
    else {
      puts("IMPROVE");
      int a, b;
      for (int i = 0; i < n; i++)
        if (!ok[i][0]) a = i;
      for (int i = 0; i < n; i++)
        if (!ok[i][1]) b = i;
      printf("%d %d\n", a + 1, b + 1);
    }
  }

  return 0;
}

// "Si puedes imaginarlo puedes programarlo" Alejandro Taboada
