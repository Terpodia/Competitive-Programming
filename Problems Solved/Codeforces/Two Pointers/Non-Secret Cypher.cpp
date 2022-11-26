//-Si puedes imaginarlo, puedes programarlo- Alejandro Taboada
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define fst first
#define snd second
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define rep(i, x, n) \
  for (__typeof(n) i = (x); i != (n); i += 1 - 2 * ((x) > (n)))
#define dbg(x) cout << #x << "=" << x << " ";
#define line cout << "\n........................................\n";
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  int a[n];
  rep(i, 0, n) scanf("%d", a + i);

  ll ans = 0;
  int l = 0, r = 0;

  map<int, int> mp;
  multiset<int> ms;
  mp[a[l]]++;
  ms.insert(1);

  while (*ms.rbegin() < k && r < n) {
    r++;
    if (r < n) {
      auto it = ms.find(mp[a[r]]);
      if (it != ms.end()) ms.erase(it);
      mp[a[r]]++;
      ms.insert(mp[a[r]]);
    }
  }
  ans += (ll)n - r;
  l++;
  if (l > r) {
    r++;
    if (r < n) {
      auto it = ms.find(mp[a[r]]);
      if (it != ms.end()) ms.erase(it);
      mp[a[r]]++;
      ms.insert(mp[a[r]]);
    }
  }

  while (l < n && r < n) {
    auto it = ms.find(mp[a[l - 1]]);
    if (it != ms.end()) ms.erase(it);
    mp[a[l - 1]]--;
    ms.insert(mp[a[l - 1]]);

    while (*ms.rbegin() < k && r < n) {
      r++;
      if (r < n) {
        it = ms.find(mp[a[r]]);
        if (it != ms.end()) ms.erase(it);
        mp[a[r]]++;
        ms.insert(mp[a[r]]);
      }
    }
    ans += (ll)n - r;
    l++;
    if (l > r) {
      r++;
      if (r < n) {
        it = ms.find(mp[a[r]]);
        if (it != ms.end()) ms.erase(it);
        mp[a[r]]++;
        ms.insert(mp[a[r]]);
      }
    }
  }

  printf("%lld\n", ans);

  return 0;
}
