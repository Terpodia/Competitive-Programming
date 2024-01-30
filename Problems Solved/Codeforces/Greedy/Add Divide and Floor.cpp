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

vector<int> ans;

ll solve(int x, int y) {
  if (x == y) return 0;

  if (x % 2 == 0) {
    ans.pb(0);
    return solve(x / 2, y / 2) + 1;
  }
  ans.pb(1);
  return solve((x + 1) / 2, (y + 1) / 2) + 1;
}

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
    sort(a, a + n);
    int m = solve(a[0], a[n - 1]);
    cout << m << "\n";
    if (m > 0 && m <= n) {
      for (ll v : ans) cout << v << " ";
      cout << "\n";
    }
    ans.clear();
  }
  return 0;
}
