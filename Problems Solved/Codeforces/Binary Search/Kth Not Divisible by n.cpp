#include <cstdio>

typedef long long ll;

const ll INF = 1e14;

ll n, k;

ll bs() {
  ll l = 0, r = INF;
  while (r > l) {
    ll mid = l + (r - l) / 2;
    if (mid - (mid / n) >= k)
      r = mid;
    else
      l = mid + 1;
  }
  return r;
}

int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    scanf("%lld%lld", &n, &k);
    printf("%lld\n", bs());
  }
  return 0;
}
