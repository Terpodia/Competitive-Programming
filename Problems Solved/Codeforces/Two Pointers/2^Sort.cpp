#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define f first
#define s second
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define rep(i, x, n) \
  for (__typeof(n) i = (x); i != (n); i += 1 - 2 * ((x) > (n)))
#define dbg(x) cout << #x << "=" << x << " ";
#define line cout << "\n...................................................\n";

typedef __uint128_t u128;

const int MAXN = 2e5;

int n, k, a[MAXN];

void solve() {
  int ans = 0;
  int l = 0, r = 1;
  while (r < n) {
    if (a[r] * 2 <= a[r - 1])
      l = r;
    else {
      if (r - l + 1 == k + 1) ans++, l++;
    }
    r++;
  }
  printf("%d\n", ans);
}

int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    scanf("%d%d", &n, &k);
    rep(i, 0, n) scanf("%d", a + i);
    solve();
  }
  return 0;
}
