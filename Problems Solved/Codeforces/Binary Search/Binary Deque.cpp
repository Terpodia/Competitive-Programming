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

const int MAXN = 2e5, INF = 1e9;

int n, s, a[MAXN], pref[MAXN + 1];

int bs(int lx) {
  int l = lx, r = n - 1;
  while (r > l) {
    int mid = l + (r - l + 1) / 2;
    if (pref[mid + 1] - pref[lx] <= s)
      l = mid;
    else
      r = mid - 1;
  }
  return l;
}

void solve() {
  if (s > pref[n]) {
    puts("-1");
    return;
  }
  int ans = INF;
  rep(l, 0, n) {
    int r = bs(l);
    if (pref[r + 1] - pref[l] != s) continue;
    ans = min(ans, l + n - 1 - r);
  }
  printf("%d\n", ans);
}

int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    scanf("%d%d", &n, &s);
    rep(i, 0, n) scanf("%d", a + i);
    pref[0] = 0;
    rep(i, 1, n + 1) pref[i] = pref[i - 1] + a[i - 1];
    solve();
  }
  return 0;
}
