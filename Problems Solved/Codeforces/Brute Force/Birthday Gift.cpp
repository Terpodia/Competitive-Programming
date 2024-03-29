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

const int MAXN = 1e5;

int n, x, a[MAXN];

int solve(vector<int>& b) {
  int res = 1, cur = 0;
  fore(i, 0, n) {
    cur ^= a[i];
    bool check = true;
    for (int j : b) {
      check &= !(cur & (1 << j));
    }
    if (check) res++, cur = 0;
  }
  bool check = true;
  for (int j : b) {
    check &= !(cur & (1 << j));
  }
  if (!check) res = 0;

  return res;
}

int main() {
  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    cin >> n >> x;
    fore(i, 0, n) cin >> a[i];
    vector<int> b;
    int ans = 0;
    for (int i = 29; i >= 0; i--) {
      if (x & (1 << i)) {
        b.pb(i);
        ans = max(ans, solve(b));
        b.pop_back();
      } else
        b.pb(i);
    }
    ans = max(ans, solve(b));
    cout << ans - 1 << "\n";
  }
  return 0;
}
