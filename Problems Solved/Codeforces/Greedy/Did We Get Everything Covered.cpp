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
    int n, k, m;
    cin >> n >> k >> m;
    string s;
    cin >> s;
    vector<int> p[26];
    fore(i, 0, m) p[s[i] - 'a'].pb(i);

    string ans = "";
    bool can = true;
    vector<int> cur(26, 0);
    int lst = -1;
    while (SZ(ans) < n) {
      int w = 0;
      fore(i, 0, k) {
        while (cur[i] < SZ(p[i]) && p[i][cur[i]] <= lst) cur[i]++;
        if (SZ(p[i]) <= cur[i]) {
          int z = SZ(ans);
          fore(j, 0, n - z) ans.pb('a' + i);
          can = false;
          break;
        }
        w = max(w, p[i][cur[i]]);
      }
      if (!can) break;
      ans.pb(s[w]);
      lst = w;
    }
    if (can)
      cout << "YES\n";
    else
      cout << "NO\n" << ans << "\n";
  }
  return 0;
}
