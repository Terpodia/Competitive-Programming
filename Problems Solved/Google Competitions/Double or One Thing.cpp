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

string s;

void solve() {
  int i = 0;
  string ans;
  while (i < sz(s)) {
    int l = i;
    while (i < sz(s) - 1 && s[i] == s[i + 1]) i++;
    for (int j = l; j <= i; j++) ans.push_back(s[j]);
    if (i == sz(s) - 1) break;
    if (s[i] < s[i + 1]) {
      for (int j = l; j <= i; j++) ans.push_back(s[j]);
    }
    i++;
  }
  cout << ans << "\n";
}

int main() {
  set_IO();
  int tt;
  cin >> tt;
  rep(_, 1, tt + 1) {
    cin >> s;
    cout << "Case #" << _ << ": ";
    solve();
  }
  return 0 - 0;
}
// "Si puedes imaginarlo puedes programarlo" Alejandro Taboada
