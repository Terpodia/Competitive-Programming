#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  int n, a, b;
  scanf("%d%d%d", &n, &a, &b);
  ll x[n];
  for (int i = 0; i < n; i++) scanf("%lld", x + i);
  ll pref[n + 1];
  pref[0] = 0;
  for (int i = 1; i <= n; i++) pref[i] = pref[i - 1] + x[i - 1];
  ll ans = pref[a];
  multiset<ll> s;
  s.insert(0);
  for (int i = a + 1; i <= n; i++) {
    s.insert(pref[i - a]);
    if (i - b - 1 >= 0) {
      s.erase(s.find(pref[i - b - 1]));
    }
    ans = max(ans, pref[i] - *s.begin());
  }

  printf("%lld\n", ans);
  return 0;
}
