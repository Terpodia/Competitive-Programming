//-Si puedes imaginarlo, puedes programarlo- Alejandro Taboada
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define fst first
#define snd second
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define rep(i, x, n) \
  for (__typeof(n) i = (x); i != (n); i += 1 - 2 * ((x) > (n)))
#define dbg(x) cout << #x << "=" << x << " ";
#define line cout << "\n........................................\n";
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n, x;
    scanf("%d%d", &n, &x);
    x--;
    vector<int> g[n];
    rep(i, 0, n - 1) {
      int u, v;
      scanf("%d%d", &u, &v);
      u--, v--;
      g[u].pb(v);
      g[v].pb(u);
    }
    if (sz(g[x]) <= 1)
      puts("Ayush");
    else if (n % 2 == 0)
      puts("Ayush");
    else
      puts("Ashish");
  }
  return 0;
}
