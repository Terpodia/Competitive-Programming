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
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> g[n];
    fore(i, 0, m) {
      int u, v;
      cin >> u >> v;
      g[u - 1].pb({v - 1, i});
      g[v - 1].pb({u - 1, i});
    }
    bool flag = false;
    fore(i, 0, n) if (SZ(g[i]) < n - 1) flag = true;
    if (flag) {
      vector<int> c(m, 1);
      fore(i, 0, n) if (SZ(g[i]) < n - 1) {
        for (auto& [u, idx] : g[i]) {
          c[idx] = 2;
        }
        break;
      }
      cout << "2\n";
      fore(i, 0, m) cout << c[i] << " ";
      cout << "\n";
      continue;
    }
    vector<int> c(m, 3);
    fore(i, 0, SZ(g[0]) - 1) { c[g[0][i].snd] = 2; }
    c[g[0].back().snd] = 1;
    cout << "3\n";
    fore(i, 0, m) cout << c[i] << " ";
  }
  return 0;
}
