// Si puedes imaginarlo puedes programarlo
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
#define erof(i, x, n) for (auto i = (x); i > (n); i--)
#define all(x) x.begin(), x.end()
#define dbg(x) cerr << #x << "=" << x << " "
#define line \
  cerr << "\n-----------------------------------------------------------\n"
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// shuffle(.begin(),.end(),rng); uniform_int_distribution<int>(a,b)(rng) [a,b]

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ll n;
  cin >> n;
  ll ans[4];
  ans[0] = 0;
  ans[1] = 6;
  ans[2] = 28;
  ans[3] = 96;
  fore(k, (ll)1, n + 1) {
    if (k <= 4)
      cout << ans[k - 1] << "\n";
    else {
      ll res = (k - 4) * (k - 4) * (k * k - 8 - 1);
      res += 4 * (k * k - 2 - 1);
      res += 8 * (k * k - 3 - 1);
      res += (k - 2 - 3 + 1) * (k * k - 4 - 1) * 4;
      res += 4 * (k * k - 4 - 1);
      res += (k - 2 - 3 + 1) * (k * k - 6 - 1) * 4;
      res /= 2;
      cout << res << "\n";
    }
  }
  return 0;
}
