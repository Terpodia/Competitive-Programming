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
    ll a[n];
    fore(i, 0, n) cin >> a[i];

    int p[2][n];
    p[0][0] = p[0][1] = 0;
    p[1][n - 1] = p[1][n - 2] = n - 1;

    /*
    int last[2][n];
    fore(k,0,2) fore(i,0,n) last[k][i] = -1;
    */

    fore(i, 1, n - 1) {
      if (a[i] - a[i - 1] < a[i + 1] - a[i]) {
        p[0][i + 1] = i + 1;
        // last[0][p[0][i]] = i;
      } else
        p[0][i + 1] = p[0][i];
    }
    // last[0][p[0][n-1]] = n-1;

    for (int i = n - 2; i > 0; i--) {
      if (a[i + 1] - a[i] < a[i] - a[i - 1]) {
        p[1][i - 1] = i - 1;
        // last[1][p[1][i]] = i;
      } else
        p[1][i - 1] = p[1][i];
    }
    // last[1][p[1][0]] = 0;

    ll pref[n + 1], suff[n + 1];
    pref[0] = 0, suff[n] = 0;

    fore(i, 1, n + 1) {
      pref[i] = pref[i - 1];
      if (i == 1) continue;
      if (p[0][i - 1] == p[0][i - 2])
        pref[i]++;
      else
        pref[i] += a[i - 1] - a[i - 2];
    }
    for (int i = n - 1; i >= 0; i--) {
      suff[i] = suff[i + 1];
      if (i == n - 1) continue;
      if (p[1][i] == p[1][i + 1])
        suff[i]++;
      else
        suff[i] += a[i + 1] - a[i];
    }

    int m;
    cin >> m;
    while (m--) {
      int x, y;
      cin >> x >> y;
      if (x < y) {
        cout << pref[y] - pref[x] << "\n";
      } else {
        swap(x, y);
        cout << suff[x - 1] - suff[y - 1] << "\n";
      }
    }
  }
  return 0;
}
