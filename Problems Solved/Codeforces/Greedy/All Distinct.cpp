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

int MAXAI = 1e4 + 7;

int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    int cnt[MAXAI];
    memset(cnt, 0, sizeof(cnt));
    rep(i, 0, n) {
      int ai;
      scanf("%d", &ai);
      cnt[ai]++;
    }
    int ans = 0, even = 0;
    rep(i, 0, MAXAI) {
      if (cnt[i] > 0) ans++;
      if (cnt[i] > 0 && cnt[i] % 2 == 0) even++;
    }
    if (even % 2 == 1) ans--;
    printf("%d\n", ans);
  }
  return 0;
}

