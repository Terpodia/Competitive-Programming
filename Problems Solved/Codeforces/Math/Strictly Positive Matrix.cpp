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

vector<int> g[2][2000];
stack<int> s;
vector<bool> vis;

void dfs(int u, int i) {
  vis[u] = true;
  for (int v : g[i][u])
    if (!vis[v]) dfs(v, i);
  if (i == 1) s.push(u);
}

int main() {
  int n;
  scanf("%d", &n);
  rep(i, 0, n) rep(j, 0, n) {
    int x;
    scanf("%d", &x);
    if (x > 0) {
      g[0][i].pb(j);
      g[1][j].pb(i);
    }
  }
  vis = vector<bool>(n, false);
  rep(i, 0, n) {
    if (!vis[i]) {
      dfs(i, 1);
    }
  }
  vis = vector<bool>(n, false);
  int cnt = 0;
  while (!s.empty()) {
    int u = s.top();
    s.pop();
    if (!vis[u]) dfs(u, 0), cnt++;
  }
  if (cnt == 1)
    puts("YES");
  else
    puts("NO");

  return 0;
}

