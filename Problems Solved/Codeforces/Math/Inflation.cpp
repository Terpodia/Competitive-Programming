/*
*************************************************************
"Si puedes imaginarlo, puedes programarlo" Alejandro Taboada.
*************************************************************
*/

#include <cmath>
#include <iostream>
using namespace std;

#define sz(x) (int)x.size()
#define forn(i, x, n) for (int i = (x); i < (int)n; i++)

const int MAXN = 100;

typedef long double ld;
typedef long long ll;

int n;
ll k, p[MAXN];

void solve() {
  ll s = p[0];
  ll ans = 0;

  forn(i, 1, n) {
    if (p[i] * 100 > k * s) {
      ll v = (p[i] * 100 + k - 1) / k;
      ans += v - s;
      s += v - s;
    }
    s += p[i];
  }

  printf("%lld\n", ans);
}

int main() {
  int t;
  scanf("%d", &t);

  while (t--) {
    scanf("%d%lld", &n, &k);
    // k *= 100;

    forn(i, 0, n) {
      scanf("%lld", p + i);
      // p[i] *= 100;
    }
    solve();
  }

  return 0;
}
