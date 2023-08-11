#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 3e5 + 7;

int n, x, y;

vector<int> g[MAXN];
bool vis[MAXN];
ll sz[MAXN];
bool has[MAXN];

void dfs(int u) {
  sz[u] = 1;
  vis[u] = true;

  if (u == y) has[u] = true;
  for (int v : g[u])
    if (!vis[v]) {
      dfs(v);
      sz[u] += sz[v];
      has[u] |= has[v];
    }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> x >> y;
  x--, y--;
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  ll c = -1;
  dfs(x);
  for (int v : g[x]) {
    if (has[v]) c = v;
  }
  ll k1 = max(sz[x] - sz[c], (ll)0);
  ll k2 = max(sz[c] - sz[y], (ll)0);
  ll k3 = sz[y];
  ll ans = k1 * (k1 + k2) + (k2 + k3) * (k1 + k2 + k3) - (k1 + k2 + k3);
  cout << ans << "\n";
  return 0;
}
