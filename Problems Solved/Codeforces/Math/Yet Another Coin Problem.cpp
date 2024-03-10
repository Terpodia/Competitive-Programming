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
  int a[5] = {1, 3, 6, 10, 15};
  // 1 1+2 1+2+3 1+2+3+4 1+2+3+4+5
  // 1*2/2 2*3/2 3*4/2 4*5/2 5*6/2
  while (tt--) {
    int n;
    cin >> n;
    int ans = n + 1;
    fore(i, 0, 3) fore(j, 0, 2) fore(k, 0, 5) fore(w, 0, 3) {
      int x = a[0] * i + a[1] * j + a[2] * k + a[3] * w;
      if (x > n || (n - x) % a[4] != 0) continue;
      ans = min(ans, i + j + k + w + (n - x) / a[4]);
    }
    cout << ans << "\n";
  }
  return 0;
}
