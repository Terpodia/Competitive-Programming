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
  int n, m;
  cin >> n >> m;
  ll a[n], b[m];
  fore(i, 0, n) cin >> a[i];
  fore(i, 0, m) cin >> b[i];
  sort(a, a + n);
  sort(b, b + m);
  ll r = max(a[1] * b[0], a[n - 1] * b[m - 1]);
  r = max(r, max(a[1] * b[m - 1], a[n - 1] * b[0]));
  ll ans = r;
  r = max(a[0] * b[0], a[n - 2] * b[m - 1]);
  r = max(r, max(a[0] * b[m - 1], a[n - 2] * b[0]));
  ans = min(ans, r);
  cout << ans << "\n";
  return 0;
}
