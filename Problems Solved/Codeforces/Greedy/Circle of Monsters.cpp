#include <algorithm>
#include <cstdio>
using namespace std;

typedef long long ll;

const ll INF = 1e18;

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);

    ll a[n], b[n];
    for (int i = 0; i < n; i++) scanf("%lld %lld", a + i, b + i);

    ll pref[n];
    pref[0] = max(a[0] - b[n - 1], 0LL);

    for (int i = 1; i < n; i++)
      pref[i] = pref[i - 1] + max(a[i] - b[i - 1], 0LL);

    ll ans = INF;

    for (int i = 0; i < n; i++) {
      if (i == 0)
        ans = min(ans, a[i] + pref[n - 1] - pref[i]);

      else if (i == n - 1)
        ans = min(ans, pref[n - 2] + a[n - 1]);

      else
        ans = min(ans, pref[i - 1] + (pref[n - 1] - pref[i]) + a[i]);
    }

    printf("%lld\n", ans);
  }

  return 0;
}
