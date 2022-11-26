#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

enum { UNVISITED = -1, EXPLORED = -2, VISITED = -3 };

typedef vector<int> vi;

const int MAXN = 1e4 + 7;

vector<pair<int, int>> g[MAXN];
vi bridge[MAXN], dfs_parent, dfs_num, dfs_low, vis, CC;
int dfsNumberCount;

vi newG[MAXN];

void findBridges(int u) {
  dfs_num[u] = dfs_low[u] = dfsNumberCount++;
  for (int i = 0; i < (int)g[u].size(); i++) {
    int v = g[u][i].first;
    int j = g[u][i].second;
    if (dfs_num[v] == UNVISITED) {
      dfs_parent[v] = u;
      findBridges(v);
      if (dfs_low[v] > dfs_num[u]) bridge[u][i] = bridge[v][j] = 1;
      dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    } else if (v != dfs_parent[u])
      dfs_low[u] = min(dfs_low[u], dfs_num[v]);
  }
}

void dfs(int u) {
  vis[u] = VISITED;
  CC[u] = dfsNumberCount;
  for (int v : newG[u]) {
    if (vis[v] == UNVISITED) {
      dfs(v);
    }
  }
}

int main() {
  int n, m, q;
  while (scanf("%d%d%d", &n, &m, &q) && (n || m || q)) {
    for (int i = 0; i < n; i++) g[i].clear();
    for (int i = 0; i < n; i++) newG[i].clear();
    for (int i = 0; i < n; i++) bridge[i].clear();
    dfs_parent = vi(n, -1);
    dfs_num = vi(n, UNVISITED);
    dfs_low = vi(n, 0);
    dfsNumberCount = 0;

    for (int i = 0; i < m; i++) {
      int u, v;
      scanf("%d%d", &u, &v);
      u--, v--;
      g[u].push_back({v, g[v].size()});
      g[v].push_back({u, g[u].size() - 1});
      bridge[u].push_back(0);
      bridge[v].push_back(0);
    }

    for (int i = 0; i < n; i++) {
      if (dfs_num[i] == UNVISITED) findBridges(i);
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < (int)g[i].size(); j++) {
        if (bridge[i][j]) {
          newG[i].push_back(g[i][j].first);
          newG[g[i][j].first].push_back(i);
        }
      }
    }

    vis = vi(n, UNVISITED);
    CC = vi(n, -1);
    dfsNumberCount = 0;
    for (int i = 0; i < n; i++) {
      if (vis[i] == UNVISITED) {
        dfs(i);
        dfsNumberCount++;
      }
    }

    while (q--) {
      int u, v;
      scanf("%d%d", &u, &v);
      u--, v--;
      (CC[u] == CC[v]) ? puts("Y") : puts("N");
    }
    puts("-");
  }
  return 0;
}
