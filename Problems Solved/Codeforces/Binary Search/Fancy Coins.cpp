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

const int INF = 1e8 + 3;

int m, k, a, b;

bool f(int n) {
  int cnt = min(m / k, b);
  int x = m - cnt * k;
  x = max(0, x - a);
  if (x > 0) {
    if (k - x % k <= a)
      cnt = (x + k - 1) / k;
    else
      cnt = x / k + x % k;
    if (cnt > n) return false;
  }
  return true;
}

int solve() {
  int l = 0, r = INF;
  while (r > l) {
    int mid = l + (r - l) / 2;
    if (f(mid))
      r = mid;
    else
      l = mid + 1;
  }
  return r;
}

int main() {
  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    cin >> m >> k >> a >> b;
    cout << solve() << "\n";
  }
  return 0;
}
