#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n, m;
    scanf("%d%d", &n, &m);
    int k[n];
    ll c[m];
    for (int i = 0; i < n; i++) scanf("%d", k + i);
    for (int i = 0; i < m; i++) scanf("%lld", c + i);
    sort(k, k + n, greater<int>());

    ll ans = 0;
    for (int i = 0; i < n; i++) {
      if (i >= m)
        ans += c[k[i] - 1];
      else
        ans += min(c[i], c[k[i] - 1]);
    }
    printf("%lld\n", ans);
  }
  return 0;
}
