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

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    int a[n][m];
    fore(i, 0, n) fore(j, 0, m) cin >> a[i][j];
    int r = 0, c = 0;
    fore(i, 0, n) {
      bool can = true;
      fore(j, 0, m) can &= a[i][j] == 0;
      if (can) r++;
    }
    fore(j, 0, m) {
      bool can = true;
      fore(i, 0, n) can &= a[i][j] == 0;
      if (can) c++;
    }
    if (min(r, c) % 2 == 1)
      cout << "Ashish\n";
    else
      cout << "Vivek\n";
  }
  return 0;
}
