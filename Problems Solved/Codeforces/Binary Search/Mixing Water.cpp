#include <algorithm>
#include <iostream>
using namespace std;

typedef long long ll;

const ll INF = 1e8, MAXT = 1e6;

ll h, c, t;

ll cmp(ll x, ll y) {
  ll r1 = ((h * ((x + 1) / 2)) + (c * (x / 2)));
  ll r2 = ((h * ((y + 1) / 2)) + (c * (y / 2)));

  if (abs(r1 * y - t * x * y) < abs(r2 * x - t * x * y))
    return x;
  else if (abs(r1 * y - t * x * y) > abs(r2 * x - t * x * y))
    return y;
  return min(x, y);
}

ll bs1() {
  ll l = 1, r = INF;

  while (r > l) {
    ll mid = l + (r - l + 1) / 2;
    ll cnth = h * mid, cntc = c * (mid - 1);

    if (cnth + cntc >= t * (mid + mid - 1))
      l = mid;
    else
      r = mid - 1;
  }

  return l + l - 1;
}

ll bs2() {
  ll l = 1, r = INF;

  while (r > l) {
    ll mid = l + (r - l) / 2;
    ll cnth = h * mid, cntc = c * (mid - 1);

    if (cnth + cntc <= t * (mid + mid - 1))
      r = mid;
    else
      l = mid + 1;
  }

  return r + r - 1;
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%lld %lld %lld", &h, &c, &t);
    printf("%lld\n", cmp(2, cmp(bs1(), bs2())));
  }

  return 0;
}
