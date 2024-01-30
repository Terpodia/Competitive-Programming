#include <bits/stdc++.h>
using namespace std;

#define SZ(x) (int)x.size()

typedef long long ll;

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  int a[n];
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  map<int, int> mp;

  ll ans = 0;
  int l = 0;
  for (int r = 0; r < n; r++) {
    mp[a[r]]++;
    while (SZ(mp) > k) {
      mp[a[l]]--;
      if (mp[a[l]] == 0) mp.erase(a[l]);
      l++;
    }
    if (l <= r) ans += (ll)r - (ll)l + 1LL;
  }
  printf("%lld\n", ans);
  return 0;
}
