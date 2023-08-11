#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  ll a[n], b[m];
  for (int i = 0; i < n; i++) scanf("%lld", a + i);
  for (int i = 0; i < m; i++) scanf("%lld", b + i);
  sort(a, a + n);
  sort(b, b + m, greater<ll>());
  ll ans = 0;
  for (int i = 0; i < min(n, m); i++) {
    if (a[i] >= b[i]) break;
    ans += b[i] - a[i];
  }
  printf("%lld\n", ans);
  return 0;
}
