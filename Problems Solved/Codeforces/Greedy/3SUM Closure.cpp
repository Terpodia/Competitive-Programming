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

const int MAXN = 2e5;
int n, a[MAXN], cntPositive, cntNegative, cntZero;
vector<int> positive, negative;

set<int> s;

void solve() {
  if (cntPositive > 2 || cntNegative > 2) {
    puts("NO");
    return;
  }
  if (cntZero > 0) {
    if (cntPositive == 0 && cntNegative == 0)
      puts("YES");
    else if (cntPositive >= 2 || cntNegative >= 2)
      puts("NO");
    else if (cntPositive > cntNegative || cntPositive < cntNegative)
      puts("YES");
    else {
      if (positive[0] + negative[0] == 0)
        puts("YES");
      else
        puts("NO");
    }
    return;
  }
  bool can = true;
  rep(i, 0, n) rep(j, i + 1, n) rep(k, j + 1, n) {
    if (s.find(a[i] + a[j] + a[k]) == s.end()) can = false;
  }
  (can) ? puts("YES") : puts("NO");
}

int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    scanf("%d", &n);
    rep(i, 0, n) scanf("%d", a + i);
    cntPositive = cntNegative = cntZero = 0;
    positive.clear();
    negative.clear();
    s.clear();
    rep(i, 0, n) s.insert(a[i]);

    rep(i, 0, n) {
      if (a[i] == 0)
        cntZero++;
      else if (a[i] > 0)
        positive.pb(a[i]), cntPositive++;
      else
        negative.pb(a[i]), cntNegative++;
    }

    solve();
  }
  return 0;
}
