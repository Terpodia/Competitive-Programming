#include <algorithm>
#include <cstdio>
using namespace std;

typedef long long ll;
typedef __uint128_t u128;

const ll INF = 1e18;

ll w, h, n;

bool f(ll k) {
  ll cntRow = k / w;
  ll cntCol = k / h;
  return (u128)cntRow * (u128)cntCol >= (u128)n;
}

ll solve() {
  ll l = 1, r = max(w * n, h * n);
  while (r > l) {
    ll mid = l + (r - l) / 2;
    if (f(mid))
      r = mid;
    else
      l = mid + 1;
  }
  return r;
}

int main() {
  scanf("%lld%lld%lld", &w, &h, &n);
  printf("%lld\n", solve());
  return 0;
}
