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

int n, k;

void solve() {
  if (n == 4 && k == 3) {
    cout << "-1\n";
    return;
  }
  int a[n];
  rep(i, 0, n) a[i] = i ^ (n - 1);

  set<pair<int, int>> ans;

  if (k > 0 && k < n - 1) {
    a[k] = n - 1, a[n - 1] = k;
    a[0] = k ^ (n - 1), a[k ^ (n - 1)] = 0;
  } else if (k == n - 1) {
    a[k] = n - 2, a[n - 2] = k;
    a[1] = 3, a[3] = 1;
    a[0] = 3 ^ (n - 1), a[3 ^ (n - 1)] = 0;
  }

  rep(i, 0, n) {
    int x = i, y = a[i];
    if (y < x) swap(x, y);
    ans.insert({x, y});
  }
  for (auto& [x, y] : ans) cout << x << " " << y << "\n";
}

int main() {
  set_IO();
  int tc;
  cin >> tc;
  while (tc--) {
    cin >> n >> k;
    solve();
  }
  return 📈;
}
