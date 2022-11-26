#include <cmath>
#include <iostream>
using namespace std;

#define rep(i, x, n) \
  for (__typeof(n) i = (x); i != (n); i += 1 - 2 * ((x) > (n)))

typedef long double ld;
typedef long long ll;

const int MAXN = 10000;
const ld EPS = 1e-6;

int n;
ll k;
ld a[MAXN];

void solve() {
  ld l = EPS, r = 1e7;
  rep(i, 0, 70) {
    ld mid = l + (r - l) / 2;
    ll sum = 0;
    rep(j, 0, n) sum += (ll)floor(a[j] / mid);
    if (sum >= k)
      l = mid;
    else
      r = mid;
  }
  printf("%Lf\n", l);
}

int main() {
  scanf("%d%lld", &n, &k);
  rep(i, 0, n) scanf("%Lf", a + i);
  solve();
  return 0;
}
