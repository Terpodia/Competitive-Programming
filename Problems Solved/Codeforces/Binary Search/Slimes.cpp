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
    vector<ll> a(n);
    vector<int> ans(n, INF);
    fore(i, 0, n) cin >> a[i];

    fore(_, 0, 2) {
      vector<ll> pref(n + 1, 0);
      vector<int> p(n, -1);

      fore(i, 1, n + 1) pref[i] = pref[i - 1] + a[i - 1];
      fore(i, 1, n) p[i] = (a[i] != a[i - 1]) ? i - 1 : p[i - 1];

      fore(i, 1, n) {
        if (a[i - 1] > a[i]) ans[i] = 1;

        if (p[i - 1] == -1 || pref[i] - a[i] <= 0) continue;
        int l =
            (int)distance(pref.begin(), lower_bound(all(pref), pref[i] - a[i]));
        l = min(l, p[i - 1] + 1);

        ans[i] = min(ans[i], i - l + 1);
      }
      reverse(all(a));
      reverse(all(ans));
    }

    fore(i, 0, n) {
      if (ans[i] == INF)
        cout << "-1 ";
      else
        cout << ans[i] << " ";
    }
    cout << "\n";
  }
  return 0;
}
