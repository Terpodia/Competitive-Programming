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
#define rep(i, x, n) \
  for (__typeof(n) i = (x); i != (n); i += 1 - 2 * ((x) > (n)))
#define dbg(x) cout << #x << "=" << x << " ";
#define line \
  cout << "\n........................................................\n";

typedef __uint128_t u128;

int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n, k;
    scanf("%d%d", &n, &k);
    int a[n];
    rep(i, 0, n) scanf("%d", a + i);
    if (k == 1) {
      int ans = 0;
      for (int i = 1; i < n - 1; i += 2) ans++;
      printf("%d\n", ans);
    }

    else {
      int ans = 0;
      rep(i, 1, n - 1) if (a[i] > a[i - 1] + a[i + 1]) ans++;
      printf("%d\n", ans);
    }
  }
  return 0;
}
