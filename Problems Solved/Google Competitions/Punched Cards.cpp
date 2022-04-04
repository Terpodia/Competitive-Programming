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

int n, m;

void solve() {
  char ans[n * 2 + 1][m * 2 + 1];
  rep(i, 0, n * 2 + 1) rep(j, 0, m * 2 + 1) ans[i][j] = 'x';

  // ans[0][0] = ans[0][1] = ans[1][0] = ans[1][1] = '.';
  rep(i, 2, m * 2 + 1) ans[0][i] = (i % 2 == 0) ? '+' : '-';
  rep(i, 2, n * 2 + 1) ans[i][0] = (i % 2 == 0) ? '+' : '|';

  for (int j = 2; j < m * 2 + 1; j += 2) {
    rep(i, 1, n * 2 + 1) ans[i][j] = (i % 2 == 0) ? '+' : '|';
  }
  for (int i = 2; i < n * 2 + 1; i += 2) {
    rep(j, 1, m * 2 + 1) ans[i][j] = (j % 2 == 0) ? '+' : '-';
  }
  rep(i, 0, n * 2 + 1) rep(j, 0, m * 2 + 1) {
    if (ans[i][j] == 'x') ans[i][j] = '.';
  }
  rep(i, 0, n * 2 + 1) rep(j, 0, m * 2 + 1) {
    cout << ans[i][j];
    if (j == m * 2) cout << "\n";
  }
}

int main() {
  set_IO();
  int tt;
  cin >> tt;
  rep(_, 1, tt + 1) {
    cin >> n >> m;
    cout << "Case #" << _ << ":\n";
    solve();
  }
  return 0 - 0;
}
// "Si puedes imaginarlo puedes programarlo" Alejandro Taboada
