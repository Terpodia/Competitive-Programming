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
    int n, k;
    cin >> n >> k;
    int l[n], r[n];
    fore(i, 0, n) cin >> l[i];
    fore(i, 0, n) cin >> r[i];
    sort(l, l + n);
    sort(r, r + n);

    vector<int> a, b;

    fore(i, 0, n - 1) {
      if (SZ(a) == 2 * k) break;
      if (l[i] == -1) continue;
      if (l[i] == l[i + 1])
        a.pb(l[i]), a.pb(l[i + 1]), l[i] = -1, l[i + 1] = -1;
    }
    fore(i, 0, n) {
      if (SZ(a) == 2 * k) break;
      if (l[i] == -1) continue;
      a.pb(l[i]);
    }
    fore(i, 0, n - 1) {
      if (SZ(b) == 2 * k) break;
      if (r[i] == -1) continue;
      if (r[i] == r[i + 1])
        b.pb(r[i]), b.pb(r[i + 1]), r[i] = -1, r[i + 1] = -1;
    }
    fore(i, 0, n) {
      if (SZ(b) == 2 * k) break;
      if (r[i] == -1) continue;
      b.pb(r[i]);
    }
    for (int i : a) cout << i << " ";
    cout << "\n";
    for (int i : b) cout << i << " ";
    cout << "\n";
  }
  return 0;
}
