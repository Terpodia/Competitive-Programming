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

const ll MOD = 1e9 + 7;

int main() {
  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    ll a[n];
    fore(i, 0, n) cin >> a[i];
    ll pref[n + 1];
    pref[0] = 0;
    fore(i, 1, n + 1) pref[i] = pref[i - 1] + a[i - 1];
    ll sum = 0, lo = 0;
    fore(i, 1, n + 1) {
      sum = max(pref[i] - lo, sum);
      lo = min(lo, pref[i]);
    }
    ll ans = pref[n];
    ans = ((ans % MOD) + MOD) % MOD;
    if (sum > 0) {
      sum %= MOD;
      fore(i, 0, k) {
        ans = (ans + sum) % MOD;
        sum = (sum * 2) % MOD;
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
