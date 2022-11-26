#include <algorithm>
#include <bitset>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int aux;
void fastIO() { cin.tie(0)->sync_with_stdio(0); }
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

typedef vector<int> vi;

#define sz(x) (int)x.size()
#define FOR(i, x, n) for (int i = (x); i < (int)(n); i++)
#define ROF(i, x, n) for (int i = (x); i > (int)(n); i--)

int n, m, f[500][500];
vi g[1010], vis, match;

int mcbm(int L) {
  if (vis[L]) return 0;
  vis[L] = 1;
  for (auto &R : g[L]) {
    if (match[R] == -1 || mcbm(match[R])) {
      match[R] = L;
      return 1;
    }
  }
  return 0;
}

int main() {
  int TC;
  scan(TC);
  FOR(_, 1, TC + 1) {
    scan(n, m);
    FOR(i, 0, n) FOR(j, 0, m) scan(f[i][j]);
    FOR(i, 0, n) FOR(j, 0, m) {
      if (f[i][j]) {
        g[i].push_back(n + j);
        g[n + j].push_back(i);
      }
    }
    match = vi(n + m, -1);
    int ans = 0;
    FOR(L, 0, n) {
      vis = vi(n, 0);
      ans += mcbm(L);
    }
    printf("Case %d: a maximum of %d nuts and bolts can be fitted together\n",
           _, ans);
    FOR(i, 0, n + m) g[i].clear();
  }
  return 0;
}
// "Si puedes imaginarlo puedes programarlo" Alejandro Taboada
