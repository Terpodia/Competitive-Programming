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

int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    int a[n];
    rep(i, 0, n) scanf("%d", a + i);
    int cnt[10];
    memset(cnt, 0, sizeof(cnt));

    vector<int> b;
    rep(i, 0, n) {
      if (cnt[a[i] % 10] > 3) continue;
      cnt[a[i] % 10]++;
      b.push_back(a[i] % 10);
    }

    bool can = false;
    rep(i, 0, sz(b)) rep(j, i + 1, sz(b)) rep(k, j + 1, sz(b)) {
      can |= (((b[i] + b[j] + b[k]) % 10) == 3);
    }

    (can) ? puts("YES") : puts("NO");
  }
  return 0;
}
