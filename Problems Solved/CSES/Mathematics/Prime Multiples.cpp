#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef __uint128_t u128;

int main() {
  ll n;
  int k;
  scanf("%lld%d", &n, &k);
  ll a[k];
  for (int i = 0; i < k; i++) scanf("%lld", a + i);

  ll ans = 0;

  for (int msk = 1; msk < (1 << k); msk++) {
    ll m = 1;
    bool ok = true;
    for (int i = 0; i < k; i++)
      if (msk & (1 << i)) {
        u128 c = m;
        c *= a[i];
        if (c > (u128)n) {
          ok = false;
          break;
        }
        m *= a[i];
      }
    if (!ok) continue;
    if (__builtin_popcount(msk) % 2 == 0)
      ans -= n / m;
    else
      ans += n / m;
  }
  printf("%lld\n", ans);
  return 0;
}
