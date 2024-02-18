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

const ll INF = 1e18;

int main() {
  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<ll> a(n), pref(n + 1, INF);
  ll S1 = 0, S2 = 0;
  fore(i, 0, n) cin >> a[i];
  sort(all(a));
  fore(i, 1, n + 1) pref[i] = min(pref[i - 1], a[i - 1] - i + 1);
  fore(i, 0, n) S1 += a[i] - (ll)i - pref[n];
  fore(i, 0, n - 1) S2 += a[i] - (ll)i - a[n - 1];

  fore(_, 0, q) {
    ll k;
    cin >> k;
    if (k <= n) {
      ll ans = pref[k] + k;
      if (k < n) ans = min(ans, a[k]);
      cout << ans << " ";
    } else if (k % 2 == n % 2) {
      ll ans = pref[n] + k;
      ll s = S1;
      ans -= max(((k - (ll)n) / 2LL - s + (ll)n - 1LL) / n, 0LL);
      cout << ans << " ";
    } else {
      ll ans = min(pref[n - 1] + k, a[n - 1]);
      ll s = S1;
      if (a[n - 1] > pref[n - 1] + k) {
        s += -(a[n - 1] - n + 1 - pref[n]);
        s += a[n - 1] - ans;
      } else {
        s = S2 + k * ((ll)n - 1LL);
      }
      ans -= max(((k - (ll)n + 1LL) / 2LL - s + (ll)n - 1LL) / (ll)n, 0LL);
      cout << ans << " ";
    }
  }
  cout << "\n";
  return 0;
}
