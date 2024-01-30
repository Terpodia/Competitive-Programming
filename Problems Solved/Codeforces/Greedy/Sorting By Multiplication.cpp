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

const int INF = 1e9;

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
    vector<int> pref(n + 1, 0), suff(n + 1, 0);

    fore(i, 2, n + 1) {
      pref[i] = pref[i - 1];
      if (a[i - 2] <= a[i - 1]) pref[i]++;
    }
    fore(i, 1, n + 1) pref[i]++;

    for (int i = n - 2; i >= 0; i--) {
      suff[i] = suff[i + 1];
      if (a[i] >= a[i + 1]) suff[i]++;
    }
    int ans = INF;
    fore(i, 0, n + 1) { ans = min(ans, pref[i] + suff[i]); }
    cout << ans << "\n";
  }
  return 0;
}
