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
#define sz(x) (int)x.size()
#define rep(i, x, n) \
  for (__typeof(n) i = (x); i != (n); i += 1 - 2 * ((x) > (n)))
#define dbg(x) cout << #x << "=" << x << " ";
#define line cout << "\n.........................................\n";

typedef long long ll;
typedef __int128_t i128;

const int MAXN = 1e6 + 2;

ll hm[MAXN], hb[MAXN];
int hsz;

void add_line(ll m, ll b) {
  while (hsz > 1) {
    if ((i128)(hb[hsz - 1] - b) * (i128)(hm[hsz - 1] - hm[hsz - 2]) <=
        (i128)(hb[hsz - 2] - hb[hsz - 1]) * (i128)(m - hm[hsz - 1])) {
      hsz--;
    } else
      break;
  }
  hm[hsz] = m;
  hb[hsz++] = b;
}

ll query(ll x) {
  int l = 0, r = hsz - 1;
  while (r > l) {
    int mid = l + (r - l + 1) / 2;
    if (mid == 0)
      l = mid;
    else if (hb[mid - 1] - hb[mid] <= x * (hm[mid] - hm[mid - 1]))
      l = mid;
    else
      r = mid - 1;
  }
  return hm[l] * x + hb[l];
}

struct rectangle {
  ll x, y, a;
  bool operator<(const rectangle& r) const { return x < r.x; }
  ll area() { return x * y; }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n;
  cin >> n;
  rectangle r[n];
  rep(i, 0, n) cin >> r[i].x >> r[i].y >> r[i].a;
  sort(r, r + n);

  ll dp[n];

  dp[0] = r[0].area() - r[0].a;
  add_line(r[0].x, dp[0]);

  rep(i, 1, n) {
    dp[i] = max(r[i].area() - r[i].a, r[i].area() - r[i].a + query(-r[i].y));
    add_line(r[i].x, dp[i]);
  }

  cout << *max_element(dp, dp + n) << "\n";

  return 0;
}

