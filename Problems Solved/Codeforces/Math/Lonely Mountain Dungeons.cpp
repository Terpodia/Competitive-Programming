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
    ll b, k;
    cin >> n >> b >> k;
    ll c[n];
    fore(i, 0, n) cin >> c[i];
    ll hi = 0;
    fore(i, 0, n) hi = max(c[i], hi);
    ll p[hi + 10];
    memset(p, 0, sizeof(p));
    fore(i, 0, n) fore(j, 1, c[i] + 1) {
      ll m = c[i] / j, x = c[i] % j;
      ll res = 0;

      if (x > 0) {
        res += (m + 1LL) * (m + 1LL) * ((x * (x - 1LL)) / 2LL);
        res += (m + 1) * ((ll)j - x) * m * x;
      }
      ll y = j - x;
      res += m * m * (y * (y - 1LL) / 2LL);

      p[j] += res * b;

      if (j < c[i]) p[j + 1] -= res * b;
    }
    fore(i, 1, hi + 10) p[i] += p[i - 1];
    fore(i, 1, hi + 10) p[i] -= k * (i - 1LL);

    ll ans = 0;
    fore(i, 1, hi + 10) ans = max(p[i], ans);
    cout << ans << "\n";
  }
  return 0;
}
