#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()

typedef long long ll;

const ll INF = 1e18;

int main() {
  int n, m = 0;
  scanf("%d", &n);

  vector<vector<ll>> a(n);

  for (int i = 0; i < n; i++) {
    int t, s;
    scanf("%d%d", &t, &s);
    a[i] = vector<ll>(s + 1);
    a[i][0] = t;
    if (t == 1) m++;
    for (int j = 1; j <= s; j++) scanf("%lld", &a[i][j]);
  }
  if (m == 0) {
    set<ll> s;
    for (int i = 0; i < n; i++) {
      for (int j = 1; j < sz(a[i]); j++) s.insert(a[i][j]);
    }
    ll ans = INF - (ll)s.size();
    printf("%lld\n", ans);
    return 0;
  }
  map<ll, int> mp;
  for (int i = 0; i < n; i++) {
    if (a[i][0] == 1) {
      for (int j = 1; j < sz(a[i]); j++) mp[a[i][j]]++;
    } else {
      for (int j = 1; j < sz(a[i]); j++) {
        auto it = mp.find(a[i][j]);
        if (it != mp.end()) mp.erase(it);
      }
    }
  }
  int ans = 0;
  for (auto [x, y] : mp)
    if (y == m) ans++;
  printf("%d\n", ans);
  return 0;
}
