#include <algorithm>
#include <bitset>
#include <chrono>
#include <cmath>
#include <cstring>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>

using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void _scan(int &x) { scanf("%d", &x); }
void _scan(long long &x) { scanf("%lld", &x); }
void _scan(double &x) { scanf("%lf", &x); }
void _scan(long double &x) { scanf("%Lf", &x); }
void _scan(char &x) { scanf(" %c", &x); }
void _scan(char *x) { scanf("%s", x); }
template <typename T>
void _scan(vector<T> &v) {
  for (int i = 0; i < (int)v.size(); i++) _scan(v[i]);
}
void scan() {}
template <typename T, typename... U>
void scan(T &head, U &...tail) {
  _scan(head);
  scan(tail...);
}

void fast_IO() { cin.tie(0)->sync_with_stdio(0); }

typedef __uint128_t u128;
#define sz(x) (int)x.size()
#define FOR(i, x, n) for (int i = (x); i < (int)(n); i++)
#define ROF(i, x, n) for (int i = (x); i > (int)(n); i--)

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
  fast_IO();
  int tc;
  cin >> tc;
  while (tc--) {
    int n, m, r, c;
    cin >> n >> m >> r >> c;
    r--, c--;
    char a[n][m];
    FOR(i, 0, n) FOR(j, 0, m) cin >> a[i][j];
    bool has_black = false;
    bool can_in_one = false;

    FOR(i, 0, n) FOR(j, 0, m) if (a[i][j] == 'B') has_black = true;
    if (!has_black)
      cout << "-1\n";
    else if (a[r][c] == 'B')
      cout << "0\n";
    else {
      FOR(i, 0, n) if (a[i][c] == 'B') can_in_one = true;
      FOR(i, 0, m) if (a[r][i] == 'B') can_in_one = true;

      if (can_in_one)
        cout << "1\n";
      else
        cout << "2\n";
    }
  }

  return 0;
}
