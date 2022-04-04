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

const int INF = 1e9, SUM = 1e6;

int C[3], M[3], Y[3], K[3];

void solve() {
  int atLeast[4] = {INF, INF, INF, INF};
  rep(i, 0, 3) atLeast[0] = min(atLeast[0], C[i]),
               atLeast[1] = min(atLeast[1], M[i]),
               atLeast[2] = min(atLeast[2], Y[i]),
               atLeast[3] = min(atLeast[3], K[i]);

  int s = 0;
  rep(i, 0, 4) s += atLeast[i];

  if (s < SUM)
    cout << "IMPOSSIBLE\n";
  else {
    rep(i, 0, 4) {
      if (s == SUM) break;
      int r = s - SUM;
      s -= min(r, atLeast[i]);
      atLeast[i] -= min(r, atLeast[i]);
    }
    rep(i, 0, 4) cout << atLeast[i] << " \n"[i == 3];
  }
}

int main() {
  set_IO();
  int tt;
  cin >> tt;
  rep(_, 1, tt + 1) {
    rep(i, 0, 3) cin >> C[i] >> M[i] >> Y[i] >> K[i];
    cout << "Case #" << _ << ": ";
    solve();
  }
  return 0 - 0;
}
// "Si puedes imaginarlo puedes programarlo" Alejandro Taboada
