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
#define line cout << "\n.........................................\n";

typedef __uint128_t u128;
typedef long long ll;

const int MAXN = 2e5;

char s[MAXN], s2[MAXN];
int n;

void solve() {
  int l = 0, r = 1, j = -1;
  ll ans = 0;

  rep(i, 0, n) s2[i] = s[i];

  while (r <= n) {
    if (r == n) {
      while (l < r) ans += (ll)r - l - 1, l++;
    }

    else {
      if (s[r] == '?') {
        if (s2[r - 1] == '1')
          s2[r] = '0';
        else if (s2[r - 1] == '0')
          s2[r] = '1';

        if (s[r - 1] != '?') j = r;
      }

      else if (s[r] == s2[r - 1]) {
        if (s[r - 1] != '?') {
          while (l < r) ans += (ll)r - l - 1, l++;
        } else {
          while (l < j) ans += (ll)r - l - 1, l++;
        }
      }
    }
    r++;
  }
  printf("%lld\n", ans + n);
}

int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    scanf("%s", s);
    n = strlen(s);
    solve();
  }
  return 0;
}
