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

typedef long long ll;

#define sz(x) (int)x.size()

struct seg {
  ll l, r, cost;
};

int main() {
  int tc;
  scan(tc);
  while (tc--) {
    int n;
    scan(n);
    seg a[n];
    for (int i = 0; i < n; i++) scan(a[i].l, a[i].r, a[i].cost);

    pair<ll, ll> lo, hi;
    seg p;

    lo = {a[0].l, a[0].cost};
    hi = {a[0].r, a[0].cost};
    p = a[0];

    printf("%lld\n", a[0].cost);

    for (int i = 1; i < n; i++) {
      if (a[i].l <= p.l && a[i].r >= p.r) {
        if (a[i].l < p.l || a[i].r > p.r)
          p = a[i];
        else if (a[i].cost < p.cost)
          p = a[i];
      } else if (a[i].l == p.l && a[i].r == p.r && a[i].cost < p.cost)
        p = a[i];

      if (a[i].l < lo.first)
        lo = {a[i].l, a[i].cost};
      else if (a[i].l == lo.first && a[i].cost < lo.second)
        lo = {a[i].l, a[i].cost};

      if (a[i].r > hi.first)
        hi = {a[i].r, a[i].cost};
      else if (a[i].r == hi.first && a[i].cost < hi.second)
        hi = {a[i].r, a[i].cost};

      if (p.l == lo.first && p.r == hi.first)
        printf("%lld\n", min(p.cost, lo.second + hi.second));
      else
        printf("%lld\n", lo.second + hi.second);
    }
  }

  return 0;
}

// "Si puedes imaginarlo puedes programarlo" Alejandro Taboada
