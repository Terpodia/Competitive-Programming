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
    ll n, x;
    cin >> n >> x;
    ll m = n - x;
    ll res = 0;
    for (ll i = 1; i * i <= m; i++) {
      if (m % i == 0) {
        ll d1 = i, d2 = m / i;
        if (d1 % 2 == 0 && d1 != d2 && (d1 + 2) / 2 >= x) res++;
        if (d2 % 2 == 0 && (d2 + 2) / 2 >= x) res++;
      }
    }
    m = n + x - 2;
    for (ll i = 1; i * i <= m; i++) {
      if (x < 2) break;
      if (m % i == 0) {
        ll d1 = i, d2 = m / i;
        if (d1 % 2 == 0 && d1 != d2 && (d1 + 2) / 2 > x) res++;
        if (d2 % 2 == 0 && (d2 + 2) / 2 > x) res++;
      }
    }
    cout << res << "\n";
  }
  return 0;
}
