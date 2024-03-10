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
    char a[2][n];
    fore(i, 0, 2) fore(j, 0, n) cin >> a[i][j];
    string s;
    s.pb(a[0][0]);

    pair<int, int> cur = mp(0, 0);
    while (cur != mp(1, n - 1)) {
      if (cur.snd == n - 1)
        s.pb(a[cur.fst + 1][cur.snd]), cur.fst++;
      else if (cur.fst == 1)
        s.pb(a[cur.fst][cur.snd + 1]), cur.snd++;
      else {
        if (a[cur.fst + 1][cur.snd] == '1')
          s.pb(a[cur.fst][cur.snd + 1]), cur.snd++;
        else if (a[cur.fst][cur.snd + 1] == '1')
          s.pb(a[cur.fst + 1][cur.snd]), cur.fst++;
        else
          s.pb(a[cur.fst][cur.snd + 1]), cur.snd++;
      }
    }

    int dp[2][n];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    fore(i, 0, 2) fore(j, 0, n) {
      if (s[i + j] != a[i][j]) continue;
      if (i == 0 && s[i + j + 1] == a[i + 1][j]) dp[i + 1][j] += dp[i][j];
      if (j < n - 1 && s[i + j + 1] == a[i][j + 1]) dp[i][j + 1] += dp[i][j];
    }

    cout << s << "\n" << dp[1][n - 1] << "\n";
  }
  return 0;
}
