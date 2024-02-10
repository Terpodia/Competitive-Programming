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
    int a[n], b[n];
    fore(i, 0, n) cin >> a[i];
    fore(i, 0, n) cin >> b[i];

    int idx[n + 1];
    fore(i, 0, n) idx[a[i]] = i;

    int i = 0, j = 0;
    ll cur = 0, ans = 0;

    while (j < n) {
      while (a[i] == -1) i++;
      if (a[i] == b[j])
        cur++, i++, j++;
      else {
        ans += cur + 1LL;
        cur = 0, a[idx[b[j++]]] = -1;
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
