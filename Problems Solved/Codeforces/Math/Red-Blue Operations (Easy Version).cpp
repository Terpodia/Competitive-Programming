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
  int n, q;
  cin >> n >> q;
  vector<ll> a(n), b(n);
  fore(i, 0, n) cin >> a[i];
  sort(all(a));
  fore(_, 0, q) {
    ll k;
    cin >> k;
    b = a;
    if (k <= n) {
      fore(i, 0, k) b[i] += k - i;
      sort(all(b));
      cout << b[0] << " ";
    } else if (k % 2 == n % 2) {
      fore(i, 0, n) b[i] += k - i;
      sort(all(b));
      ll s = 0;
      fore(i, 1, n) s += b[i] - b[0];
      b[0] -= max(((k - (ll)n) / 2LL - s + (ll)n - 1LL) / n, 0LL);
      cout << b[0] << " ";
    } else {
      fore(i, 0, n - 1) b[i] += k - i;
      sort(all(b));
      ll s = 0;
      fore(i, 1, n) s += b[i] - b[0];
      b[0] -= max(((k - (ll)n + 1LL) / 2LL - s + (ll)n - 1LL) / n, 0LL);
      cout << b[0] << " ";
    }
  }
  cout << "\n";
  return 0;
}
