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
typedef long long ll;

const int MAXN = 4e5, INF = 1e9;

int n, a[MAXN];
ll I;

ll cost(ll k) {
  ll ret = 0, p = 1;
  while (p < k) p *= 2, ret++;
  return ret * (ll)n;
}

void solve() {
  int l = 0, r = 0, k = 0, ans = INF;
  while (r < n) {
    while (r + 1 < n && a[r] == a[r + 1]) r++;
    k++;

    while (cost((ll)k) > I * 8) {
      while (l + 1 < n && a[l] == a[l + 1]) l++;
      l++;
      k--;
    }

    ans = min(ans, l + n - 1 - r);
    r++;
  }
  printf("%d\n", ans);
}

int main() {
  scanf("%d%lld", &n, &I);
  rep(i, 0, n) scanf("%d", a + i);
  sort(a, a + n);
  solve();
  return 0;
}

