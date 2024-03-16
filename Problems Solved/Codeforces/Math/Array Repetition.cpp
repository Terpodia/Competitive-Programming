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

const ll INF = 2e18;

int main() {
  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, q;
    cin >> n >> q;
    ll lst[n + 1], sz[n + 1];
    lst[0] = sz[0] = 0;
    vector<int> pos;
    bool flag = true;
    fore(i, 1, n + 1) {
      int b;
      ll x;
      cin >> b >> x;
      if (b == 1) {
        sz[i] = sz[i - 1] + 1;
        lst[i] = x;
      } else {
        lst[i] = lst[i - 1];
        long double j = sz[i - 1], k = x + 1, m = INF;
        if (j > m / k)
          sz[i] = INF;
        else
          sz[i] = sz[i - 1] * (x + 1LL);

        if (flag) pos.pb(i);
        if (sz[i] == INF) flag = false;
      }
    }
    while (q--) {
      ll k;
      cin >> k;
      for (int i = SZ(pos) - 1; i >= 0; i--) {
        int idx = pos[i];
        if (sz[idx] <= k || sz[idx - 1] >= k) continue;
        if (k % sz[idx - 1] == 0) {
          k = sz[idx - 1];
          break;
        }
        k %= sz[idx - 1];
      }
      ll ans = lst[lower_bound(sz + 1, sz + n, k) - sz];
      cout << ans << " ";
    }
    cout << "\n";
  }
  return 0;
}
