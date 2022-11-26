#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int MAXN = 200;

vector<int> g[MAXN], vis(MAXN, 0), p(MAXN, -1), dfs_num(MAXN, 0),
    dfs_low(MAXN, 0), articulation_points(MAXN, 0);

int N, dfsNumberCount, dfsRoot, dfsRootChildren;

void dfs(int u) {
  dfs_num[u] = dfs_low[u] = dfsNumberCount++;
  vis[u] = 1;
  for (int v : g[u]) {
    if (!vis[v]) {
      p[v] = u;
      if (u == dfsRoot) dfsRootChildren++;

      dfs(v);
      if (dfs_low[v] >= dfs_num[u]) {
        articulation_points[u] = 1;
      }

      dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }

    else if (v != p[u]) {
      dfs_low[u] = min(dfs_low[u], dfs_num[v]);
    }
  }
}

int main() {
  while (scanf("%d", &N) != EOF && N) {
    int u;
    while (scanf("%d", &u) != EOF && u) {
      char line[200];
      scanf("%[^\n]s", line);
      getchar();

      char* pch = strtok(line, " ");
      while (pch != NULL) {
        int v = atoi(pch);
        g[u - 1].push_back(v - 1);
        g[v - 1].push_back(u - 1);
        pch = strtok(NULL, " ");
      }
    }

    dfs(dfsRoot);

    int ans = 0;
    articulation_points[dfsRoot] = (dfsRootChildren > 1);
    for (int i = 0; i < N; i++) ans += articulation_points[i];
    printf("%d\n", ans);

    for (int i = 0; i < N; i++) g[i].clear();
    p = vector<int>(MAXN, -1);
    vis = vector<int>(MAXN, 0);
    dfs_num = vector<int>(MAXN, 0);
    dfs_low = vector<int>(MAXN, 0);
    articulation_points = vector<int>(MAXN, 0);
    dfsRootChildren = dfsNumberCount = 0;
  }
  return 0;
}
