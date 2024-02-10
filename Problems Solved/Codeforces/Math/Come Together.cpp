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
    int x[3], y[3];
    fore(i, 0, 3) cin >> x[i] >> y[i];

    pair<int, int> db, dc;
    db = mp(x[2] - x[0], y[2] - y[0]);
    dc = mp(x[1] - x[0], y[1] - y[0]);

    int ans = 1;
    if ((db.fst < 0 && dc.fst < 0) || (db.fst > 0 && dc.fst > 0))
      ans += min(abs(db.fst), abs(dc.fst));

    if ((db.snd < 0 && dc.snd < 0) || (db.snd > 0 && dc.snd > 0))
      ans += min(abs(db.snd), abs(dc.snd));

    cout << ans << "\n";
  }
  return 0;
}
