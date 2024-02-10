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
    int n, k, x;
    cin >> n >> k >> x;
    if (x != 1) {
      cout << "YES\n";
      cout << n << "\n";
      fore(i, 0, n) cout << "1 ";
      cout << "\n";
    } else if (n % 2 == 0 && k >= 2) {
      cout << "YES\n";
      cout << n / 2 << "\n";
      fore(i, 0, n / 2) cout << "2 ";
      cout << "\n";
    } else if (n != 1 && k >= 3) {
      cout << "YES\n";
      vector<int> ans;
      while (n - 2 > 1) ans.pb(2), n -= 2;
      ans.pb(3);
      cout << SZ(ans) << "\n";
      fore(i, 0, SZ(ans)) cout << ans[i] << " ";
      cout << "\n";
    } else
      cout << "NO\n";
  }
  return 0;
}
