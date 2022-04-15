#include <algorithm>
#include <cstdio>
using namespace std;

typedef long long ll;

const ll INF = 1e18;

int main() {
  ll f[16];
  f[0] = 1;
  for (int i = 1; i < 16; i++) f[i] = f[i - 1] * i;

  int tt;
  scanf("%d", &tt);
  while (tt--) {
    ll n;
    scanf("%lld", &n);
    ll ans = INF;
    for (ll msk = 0; msk < (1 << 16); msk++) {
      ll m = n;
      for (ll i = 0; i < 16; i++) {
        if (m < 0) break;
        if (msk & (1LL << i)) m -= f[i];
      }
      if (m < 0) continue;
      ll cnt = __builtin_popcountll(msk) + __builtin_popcountll(m);
      ans = min(ans, cnt);
    }
    printf("%lld\n", ans);
  }
  return 0;
}

