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
  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    int a[n];
    fore(i, 0, n) cin >> a[i];
    int lst = 0;
    bool can = true;
    fore(i, 0, n) {
      bool flag1 = false, flag2 = false;
      if (a[i] >= lst) flag1 = true;
      if (a[i] >= 10) {
        flag2 = true;
        int x = a[i] / 10, j = a[i] % 10;
        while (x > 0) {
          flag2 &= x % 10 <= j;
          j = x % 10;
          x /= 10;
        }
        flag2 &= lst <= j;
      }
      if (flag2)
        lst = a[i] % 10;
      else if (flag1)
        lst = a[i];
      else {
        can = false;
        break;
      }
    }
    if (can)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
