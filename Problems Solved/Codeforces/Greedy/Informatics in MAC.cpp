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
    cin >> n;
    int a[n];
    fore(i, 0, n) cin >> a[i];
    bool b[n];
    memset(b, false, sizeof(b));
    fore(i, 0, n) b[a[i]] = true;
    int j = -1;
    fore(i, 0, n) if (!b[i]) {
      j = i;
      break;
    }
    if (j == -1) {
      cout << "-1\n";
      continue;
    }
    if (j == 0) {
      cout << "2\n1 " << n - 1 << "\n" << n << " " << n << "\n";
      continue;
    }
    int cnt = 0;
    memset(b, false, sizeof(b));
    vector<pair<int, int>> ans;
    fore(i, 0, n) {
      if (!b[a[i]]) {
        b[a[i]] = true;
        if (a[i] < j) cnt++;
      }
      if (cnt == j) {
        ans.pb(mp(1, i + 1));
        break;
      }
    }
    memset(b, false, sizeof(b));
    cnt = 0;
    fore(i, ans[0].snd, n) {
      if (!b[a[i]]) {
        b[a[i]] = true;
        if (a[i] < j) cnt++;
      }
      if (cnt == j) {
        ans.pb(mp(ans[0].snd + 1, n));
        break;
      }
    }
    if (SZ(ans) < 2)
      cout << "-1\n";
    else {
      cout << SZ(ans) << "\n";
      fore(i, 0, SZ(ans)) cout << ans[i].fst << " " << ans[i].snd << "\n";
    }
  }
  return 0;
}
