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
typedef long long ll;

ll hc, dc, hm, dm, k, w, a;

bool check(ll t) {
  ll v1 = dc * ((t + 1) / 2);
  ll v2 = dm * (t / 2);
  return (hc - v2 <= 0 || hm - v1 <= 0);
}

ll bs() {
  ll l = 1, r = ((hm + dc - 1) / dc) * 2 + 7;
  r = min(r, ((hc + dm - 1) / dm) * 2 + 7);
  while (r > l) {
    ll mid = l + (r - l) / 2;
    if (check(mid))
      r = mid;
    else
      l = mid + 1;
  }
  return r;
}

bool solve() {
  ll t = bs();
  ll r1 = hc - (t / 2) * dm, r2 = hm - ((t + 1) / 2) * dc;

  if (r1 <= 0 && r2 <= 0) return true;
  if (r1 > 0) return true;

  return false;
}

int main() {
  set_IO();
  int tc;
  cin >> tc;
  while (tc--) {
    cin >> hc >> dc >> hm >> dm >> k >> w >> a;
    bool can = false;

    rep(i, 0, k + 1) {
      hc += i * a;
      dc += (k - i) * w;

      can |= solve();

      hc -= i * a;
      dc -= (k - i) * w;
    }

    if (!can)
      cout << "NO\n";
    else
      cout << "YES\n";
  }
  return 0;
}
