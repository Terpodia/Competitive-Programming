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
    vector<int> v;
    v.push_back(a[0]);
    fore(i, 1, n) {
      if (a[i] == a[i - 1]) continue;
      v.push_back(a[i]);
    }
    if (SZ(v) <= 2)
      cout << SZ(v) << "\n";
    else {
      int flag, ans = 2;
      if (v[0] < v[1])
        flag = 1;
      else
        flag = 2;
      fore(i, 1, SZ(v) - 1) {
        if (v[i] < v[i + 1] && flag == 2) {
          flag = 1, ans++;
        } else if (v[i] > v[i + 1] && flag == 1) {
          flag = 2, ans++;
        }
      }
      cout << ans << "\n";
    }
  }
  return 0;
}
