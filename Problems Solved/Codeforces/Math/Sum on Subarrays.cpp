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

vector<int> f(int n, int k) {
  if (n == 0) {
    vector<int> ret;
    return ret;
  }
  if (k < n) {
    vector<int> ret;
    fore(i, 0, k - 1) ret.pb(-1);
    if (k - 1 >= 0) ret.pb(200);
    ret.pb(-400);
    while (SZ(ret) < n) ret.pb(-1);
    return ret;
  }
  vector<int> ret = f(n - 1, k - n);
  ret.pb(1000);
  return ret;
}

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
    vector<int> ans = f(n, k);
    for (int i : ans) cout << i << " ";
    cout << "\n";
  }
  return 0;
}
