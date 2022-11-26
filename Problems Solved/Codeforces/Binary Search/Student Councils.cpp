// -Si puedes imaginarlo, puedes programarlo- Alejandro Taboada
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
#define line cout << "\n............................................\n";

typedef long long ll;

int n;
ll k, a[50];

bool can(ll m) {
  ll cnt = 0, j = 0;
  rep(i, 0, n) {
    ll z = j;
    ll w = min(a[i], m - j);

    j += w;
    if (j == m) cnt++;
    j %= m;
    j += min(a[i] - w, z);
  }
  return cnt >= k;
}

ll solve() {
  ll l = 0, r = (ll)1e18;
  while (r > l) {
    ll mid = l + (r - l + 1) / 2;
    if (mid == 0 || can(mid))
      l = mid;
    else
      r = mid - 1;
  }
  return l;
}

int main() {
  scanf("%lld%d", &k, &n);
  rep(i, 0, n) scanf("%lld", a + i);
  printf("%lld\n", solve());
  return 0;
}
