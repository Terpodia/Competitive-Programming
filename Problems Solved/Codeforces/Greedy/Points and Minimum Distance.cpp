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

int cnt[1020];

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
    int a[2 * n];
    fore(i, 0, 2 * n) cin >> a[i];
    memset(cnt, 0, sizeof(cnt));
    fore(i, 0, 2 * n) cnt[a[i]]++;
    int acc = 0;
    vector<pair<int, int>> ans;

    int l = 0, r = 1000;
    while (r > l) {
      if (cnt[r] == 0)
        r--;
      else if (cnt[l] == 0)
        l++;
      else {
        ans.push_back(make_pair(l, r));
        cnt[l]--, cnt[r]--;
      }
    }
    while (l <= 1000) {
      while (cnt[l] > 0) {
        ans.push_back(make_pair(l, l));
        cnt[l] -= 2;
      }
      l++;
    }
    fore(i, 0, SZ(ans) - 1) acc +=
        abs(ans[i].fst - ans[i + 1].fst) + abs(ans[i].snd - ans[i + 1].snd);

    cout << acc << "\n";
    for (auto [x, y] : ans) cout << x << " " << y << "\n";
  }
  return 0;
}
