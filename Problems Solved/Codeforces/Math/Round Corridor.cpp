#include <algorithm>
#include <cstdio>
using namespace std;

typedef long long ll;

ll n, m, k;

ll calc(ll x, ll y) {
  if (x == 1) {
    return (y - 1) / (n / k);
  }
  return (y - 1) / (m / k);
}

int main() {
  int q;
  scanf("%lld%lld%d", &n, &m, &q);

  k = __gcd(n, m);

  while (q--) {
    ll sx, sy, cx, cy;
    scanf("%lld%lld%lld%lld", &sx, &sy, &cx, &cy);
    printf("%s\n", (calc(sx, sy) == calc(cx, cy)) ? "YES" : "NO");
  }
  return 0;
}
