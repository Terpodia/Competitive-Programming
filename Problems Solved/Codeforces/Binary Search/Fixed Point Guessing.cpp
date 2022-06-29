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

int n;

int query(int l, int r) {
  l++, r++;
  cout << "? " << l << " " << r << endl;
  int cnt = 0;
  rep(i, 0, r - l + 1) {
    int x;
    cin >> x;
    if (x >= l && x <= r) cnt++;
  }
  return cnt;
}

int bs() {
  int l = 0, r = n - 1;
  while (r > l) {
    int mid = l + (r - l) / 2;
    if (query(l, mid) % 2 == 1)
      r = mid;
    else
      l = mid + 1;
  }
  return r + 1;
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    cin >> n;
    int x = bs();
    cout << "! " << x << endl;
  }
  return 0;
}

