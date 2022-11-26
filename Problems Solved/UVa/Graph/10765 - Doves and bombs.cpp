#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

typedef vector<int> vi;

const int MAXN = 1e4 + 7;

enum { UNVISITED = -1, EXPLORED = -2, VISITED = -3 };

int n, m, dfsRoot, rootChildrens, dfsNumberCount;
vi g[MAXN], pigeon_value, dfs_num, dfs_low, dfs_parent;

void dfs(int u) {
  dfs_num[u] = dfs_low[u] = dfsNumberCount++;
  for (int v : g[u])
    if (v != dfs_parent[u]) {
      if (dfs_num[v] == UNVISITED) {
        dfs_parent[v] = u;
        if (u == dfsRoot) rootChildrens++;
        dfs(v);
        if (dfs_low[v] >= dfs_num[u]) pigeon_value[u]++;
        dfs_low[u] = min(dfs_low[u], dfs_low[v]);
      } else
        dfs_low[u] = min(dfs_low[u], dfs_num[v]);
    }
}

int main() {
  while (scanf("%d%d", &n, &m) != EOF && n && m) {
    for (int i = 0; i < n; i++) g[i].clear();
    pigeon_value = vi(n, 1);
    dfs_num = vi(n, UNVISITED);
    dfs_low = vi(n, 0);
    dfs_parent = vi(n, -1);
    rootChildrens = dfsNumberCount = 0;

    int u, v;
    while (scanf("%d%d", &u, &v) != EOF && u != -1 && v != -1) {
      g[u].push_back(v);
      g[v].push_back(u);
    }

    dfs(dfsRoot);
    pigeon_value[dfsRoot] = (rootChildrens < 2) ? 1 : pigeon_value[dfsRoot] - 1;

    pair<int, int> ans[n];
    for (int i = 0; i < n; i++) ans[i] = {i, pigeon_value[i]};

    sort(ans, ans + n,
         [](const pair<int, int> p1, const pair<int, int> p2) -> bool {
           if (p1.second != p2.second) return p1.second > p2.second;
           return p1.first < p2.first;
         });

    for (int i = 0; i < m; i++) printf("%d %d\n", ans[i].first, ans[i].second);
    puts("");
  }
  return 0;
}
