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
typedef vector<int> vi;
typedef vector<vi> vvi;

const int INF = 1e9;

int main() {
  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;

  int cnt0 = 0, cnt1 = 0;
  for (char c : s) (c == '0') ? cnt0++ : cnt1++;

  int n = SZ(s);

  vvi dp[2];
  dp[0] = dp[1] = vvi(n + 1, vi(n * n + 1, INF));

  dp[0][0][0] = 0;

  fore(i, 1, n + 1) {
    dp[1] = vvi(n + 1, vi(n * n + 1, INF));
    fore(j, 0, cnt0 + 1) {
      fore(k, 0, n * n + 1) {
        if (j + 1 <= n)
          dp[1][j + 1][k] =
              min(dp[1][j + 1][k], dp[0][j][k] + (s[i - 1] != '0'));
        if (k + j < n * n + 1)
          dp[1][j][k + j] =
              min(dp[1][j][k + j], dp[0][j][k] + (s[i - 1] != '1'));
      }
    }
    swap(dp[0], dp[1]);
  }

  cout << dp[0][cnt0][(cnt0 * cnt1) / 2] / 2 << "\n";

  return 0;
}
