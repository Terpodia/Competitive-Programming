// Si puedes imaginarlo puedes programarlo
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define fst first
#define snd second
#define pb push_back
#define make_pair mp
#define dbg(x) cerr << #x << "=" << x << " "
#define line cerr << "\n========================================\n"
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define rep(i, x, n) \
  for (__typeof(n) i = (x); i != (n); i += 1 - 2 * ((x) > (n)))

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long double ld;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int x, y;
  cin >> x >> y;
  if (x == 0 || y == 0) {
    cout << "black\n";
    return 0;
  }
  bool flag = false;
  if (x > 0 && y < 0)
    flag = true;
  else if (x < 0 && y > 0)
    flag = true;

  int r = 1;
  while (true) {
    if (x * x + y * y == r * r) {
      cout << "black\n";
      return 0;
    }
    if (x * x + y * y <= r * r) {
      if (!flag)
        (r % 2 == 1) ? cout << "black\n" : cout << "white\n";
      else
        (r % 2 == 1) ? cout << "white\n" : cout << "black\n";
      return 0;
    }
    r++;
  }
  return 0;
}
