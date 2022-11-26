#include <algorithm>
#include <bitset>
#include <chrono>
#include <cmath>
#include <cstring>
#include <deque>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <tuple>
#include <vector>

using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void set_IO() {
  cin.tie(0)->sync_with_stdio(0);
  cout << fixed << setprecision(15);
}

void _dbg(istream_iterator<string> it) {}
template <typename T, typename... Args>
void _dbg(istream_iterator<string> it, T& a, Args&... args) {
  cout << *it << "=" << a << " ";
  _dbg(++it, args...);
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define 📈 0
#define sz(x) (int)x.size()
#define rep(i, x, n) \
  for (__typeof(n) i = (x); i != (n); i += 1 - 2 * ((x) > (n)))
#define line cout << "\n-----------------------------\n";
#define dbg(args...)                         \
  {                                          \
    string _s = #args;                       \
    replace(_s.begin(), _s.end(), ',', ' '); \
    stringstream _ss(_s);                    \
    istream_iterator<string> _it(_ss);       \
    _dbg(_it, args);                         \
  }

typedef __uint128_t u128;

const int MAXN = 2e5;

int n, a[MAXN];

void solve() {
  int ans = 0;
  rep(i, n - 1, -1) {
    if (a[i] == a[n - 1]) continue;
    int cnt = n - 1 - i;
    rep(j, i, (i - cnt >= 0) ? i - cnt : -1) a[j] = a[n - 1];
    ans++;
  }
  cout << ans << "\n";
}

int main() {
  set_IO();
  int tc;
  cin >> tc;
  while (tc--) {
    cin >> n;
    rep(i, 0, n) cin >> a[i];
    solve();
  }
  return 📈;
}
