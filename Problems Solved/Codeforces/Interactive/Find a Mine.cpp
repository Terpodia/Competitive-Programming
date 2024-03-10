#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// ordered_set<int> x; x.find_by_order(y); x.order_of_key(y)

#define fst first
#define snd second
#define pb push_back
#define mp make_pair
#define SZ(x) (int)x.size()
#define fore(i, x, n) for (auto i = (x); i < (n); i++)
#define all(x) x.begin(), x.end()
#define dbg(x) cerr << #x << "=" << x << " "
#define raya \
  cerr << "\n-----------------------------------------------------------\n"
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// shuffle(.begin(),.end(),rng); uniform_int_distribution<int>(a,b)(rng) [a,b]
typedef long long ll;
typedef long double ld;

int n, m;

int query(int x, int y) {
  if (x <= 0 || y <= 0 || x > n || y > m) return -1;
  cout << "? " << x << " " << y << endl;
  int res;
  cin >> res;
  return res;
}

void ans(int x, int y) { cout << "! " << x << " " << y << endl; }

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    cin >> n >> m;
    // x-1+y-1=k => x+y = k+2
    int k = query(1, 1);
    int ry = max(1, k + 2 - n), rx = k + 2 - ry;
    int cx = max(1, k + 2 - m), cy = k + 2 - cx;

    int p = query(rx, ry), q = query(cx, cy);
    if (query((k + 2 - p + rx - ry) / 2, k + 2 - (k + 2 - p + rx - ry) / 2) ==
        0) {
      ans((k + 2 - p + rx - ry) / 2, k + 2 - (k + 2 - p + rx - ry) / 2);
    } else {
      ans(k + 2 - (k + 2 - q - cx + cy) / 2, (k + 2 - q - cx + cy) / 2);
    }
  }
  return 0;
}
