// Si puedes imaginarlo puedes programarlo
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define fst first
#define snd second
#define pb push_back
#define make_pair mp
#define dbg(x) cerr << #x << "=" << x << " "
#define line cerr << "\n========================================\n"
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define rep(i, x, n) \
  for (__typeof(n) i = (x); i != (n); i += 1 - 2 * ((x) > (n)))

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = 2e5;

vector<int> g[MAXN];
int h[MAXN], anc[MAXN][31];

void dfs(int u, int p = -1) {
  if (p != -1) h[u] = h[p] + 1;
  anc[u][0] = p;
  rep(i, 1, 31) {
    if (anc[u][i - 1] != -1)
      anc[u][i] = anc[anc[u][i - 1]][i - 1];
    else
      break;
  }
  for (int v : g[u])
    if (p != v) {
      dfs(v, u);
    }
}

bool solve(int x, int y) {
  if (h[x] < h[y]) return false;
  rep(i, 30, -1) {
    if (anc[x][i] != -1 && h[anc[x][i]] >= h[y]) x = anc[x][i];
  }
  return x == y;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, q;
  cin >> n >> q;
  vector<bool> out_zero(n, false);
  rep(i, 0, n) {
    int v;
    cin >> v;
    if (v != -1)
      g[i + 1].pb(v + 1), g[v + 1].pb(i + 1);
    else
      out_zero[i] = true;
  }
  rep(i, 0, n) if (out_zero[i]) { g[0].pb(i + 1), g[i + 1].pb(0); }
  dfs(0);

  while (q--) {
    int x, y;
    cin >> x >> y;
    x++, y++;
    if (solve(x, y))
      cout << "Yes\n";
    else
      cout << "No\n";
  }
  return 0;
}
