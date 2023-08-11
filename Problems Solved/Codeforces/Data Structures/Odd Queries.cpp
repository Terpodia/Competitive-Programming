#include <cstdio>

typedef long long ll;

int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n, q;
    scanf("%d%d", &n, &q);
    ll a[n];
    for (int i = 0; i < n; i++) scanf("%lld", a + i);
    ll pref[n + 1];
    pref[0] = 0;
    for (int i = 1; i <= n; i++) pref[i] = pref[i - 1] + a[i - 1];
    while (q--) {
      int l, r;
      ll k;
      scanf("%d%d%lld", &l, &r, &k);
      if ((pref[n] - pref[r] + pref[l - 1] + k * (ll)(r - l + 1)) % 2 == 1)
        puts("YES");
      else
        puts("NO");
    }
  }
  return 0;
}
