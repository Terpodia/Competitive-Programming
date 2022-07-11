#include <algorithm>
#include <cstring>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

#define f first
#define s second
#define pb push_back
#define sz(x) (int)x.size()
#define rep(i, x, n) \
  for (__typeof(n) i = (x); i != (n); i += 1 - 2 * ((x) > (n)))
#define dbg(x) cout << #x << "=" << x << " ";
#define line cout << "\n........................................\n";

typedef pair<int, int> ii;

const int MAXN = 1e5;

struct hashi {
  size_t operator()(const ii& p) const { return p.first + 157 * p.second; }
};

int n, m, c[MAXN], id[MAXN], cnt, ans;
vector<int> g[MAXN];
bool vis[MAXN];

int sz[MAXN];
unordered_map<ii, vector<ii>, hashi> mp;

int calcId(int u) {
  vis[u] = true, id[u] = cnt;
  int ret = 1;
  for (int v : g[u])
    if (!vis[v] && c[u] == c[v]) ret += calcId(v);
  return ret;
}

void condenseGraph(int u) {
  vis[u] = true;
  ans = max(ans, sz[u]);
  for (int v : g[u]) {
    if (c[u] != c[v]) {
      mp[{min(c[u], c[v]), max(c[u], c[v])}].pb({id[u], id[v]});
    }
    if (!vis[v]) {
      condenseGraph(v);
    }
  }
}

int dfs(int u) {
  vis[u] = true;
  int ret = sz[u];
  for (int v : g[u]) {
    if (!vis[v]) ret += dfs(v);
  }
  return ret;
}

void solve() {
  memset(vis, false, sizeof(vis));
  ans = 0, cnt = 0;
  rep(i, 0, n) if (!vis[i]) sz[cnt++] = calcId(i);

  memset(vis, false, sizeof(vis));
  rep(i, 0, n) if (!vis[i]) { condenseGraph(i); }
  rep(i, 0, n) g[i].clear();

  memset(vis, false, sizeof(vis));

  for (auto it = mp.begin(); it != mp.end(); it++) {
    for (auto& [u, v] : it->second) {
      g[u].pb(v);
      g[v].pb(u);
    }
    for (auto& [u, v] : it->second) {
      if (!vis[u]) ans = max(ans, dfs(u));
      if (!vis[v]) ans = max(ans, dfs(u));
    }
    for (auto& [u, v] : it->second) {
      vis[u] = vis[v] = false;
      g[u].clear();
      g[v].clear();
    }
  }

  cout << ans << "\n";
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m;
  rep(i, 0, n) cin >> c[i];
  rep(i, 0, m) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].pb(v);
    g[v].pb(u);
  }
  solve();
  return 0;
}

