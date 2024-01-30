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
    cin >> n;
    ll c[n];
    fore(i, 0, n) cin >> c[i];
    ll ans = 0;
    fore(i, 0, n) {
      if (c[i] > 0)
        c[i]--;
      else if (c[i] == 0 && i + 1 < n && c[i + 1] > 0)
        ans++;
    }
    ll cnt = 0;
    if (c[0] > 0) cnt++;
    fore(i, 0, n) {
      if (c[i] == 0 && i + 1 < n && c[i + 1] > 0) cnt++;
    }

    map<ll, vector<int>> mp;
    fore(i, 0, n) if (c[i] != 0) mp[c[i]].pb(i);

    ll r = 0;

    for (auto it = mp.begin(); it != mp.end(); it++) {
      ans += cnt * (it->fst - r);
      r += it->fst - r;
      for (int i : it->snd) {
        if (i - 1 >= 0 && c[i - 1] > 0 && i + 1 < n && c[i + 1] > 0)
          cnt++;
        else if ((i - 1 < 0 || c[i - 1] == 0) && (i + 1 >= n || c[i + 1] == 0))
          cnt--;
        c[i] = 0;
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
