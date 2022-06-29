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
    int n;
    scanf("%d", &n);
    int a[n];
    rep(i, 0, n) scanf("%d", a + i);
    int acc = 0;
    rep(i, 0, n) acc ^= a[i];

    int x = 0;
    rep(i, 0, n) {
      if ((acc ^ a[i]) == a[i]) x = a[i];
    }
    printf("%d\n", x);
  }
  return 0;
}

