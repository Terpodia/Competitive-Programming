#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 2e5 + 7;

int n, a[MAXN];
vector<int> G[MAXN];
bool vis[MAXN];

int DFS(int u) {
  vis[u] = true;
  int ret = 1;
  for (int v : G[u]) {
    if (!vis[v]) ret += DFS(v);
  }

  return ret;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", a + i);

  int i = 0, j = n - 1;

  vector<int> nodes;

  while (i <= j) {
    G[a[i]].push_back(a[j]);
    G[a[j]].push_back(a[i]);
    nodes.push_back(a[i]);
    nodes.push_back(a[j]);
    i++, j--;
  }

  int ans = 0;

  for (int i = 0; i < (int)nodes.size(); i++) {
    if (!vis[nodes[i]]) ans += DFS(nodes[i]) - 1;
  }

  printf("%d\n", ans);

  return 0;
}
