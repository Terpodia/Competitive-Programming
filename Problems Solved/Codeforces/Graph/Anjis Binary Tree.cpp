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

const int MAXN = 3e5 + 10, INF = 1e9;

string s;

int l[MAXN], r[MAXN];

int solve(int u) {
  if (l[u] == -1 && r[u] == -1) return 0;
  int ans = INF;
  if (s[u] == 'U') {
    if (l[u] != -1) ans = min(ans, solve(l[u]) + 1);
    if (r[u] != -1) ans = min(ans, solve(r[u]) + 1);
    return ans;
  }
  if (s[u] == 'R') {
    if (l[u] != -1) ans = min(ans, solve(l[u]) + 1);
    if (r[u] != -1) ans = min(ans, solve(r[u]));
    return ans;
  }
  if (l[u] != -1) ans = min(ans, solve(l[u]));
  if (r[u] != -1) ans = min(ans, solve(r[u]) + 1);
  return ans;
}

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
    cin >> s;
    fore(i, 0, n) {
      cin >> l[i] >> r[i];
      l[i]--, r[i]--;
    }
    cout << solve(0) << "\n";
  }
  return 0;
}
