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
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    int cnt = 0;
    if (b > a) cnt++;
    if (c > a) cnt++;
    if (d > a) cnt++;
    printf("%d\n", cnt);
  }
  return 0;
}

