#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
int aux;

const int MAXN = 1e5, INF = 1e9;

pair<int, pair<int, int>> edge;

int n, k, a[MAXN], x;
vector<int> G[MAXN];

int DFS(int u, int p = -1, int d = 0) {
  int ret = a[u];

  for (int v : G[u])
    if (v != p && v != -1) {
      ret ^= DFS(v, u, d + 1);
    }

  if (p != -1 && ret == x && edge.first < d) {
    edge.first = d;
    edge.second.first = p;
    for (int i = 0; i < (int)G[p].size(); i++)
      if (G[p][i] == u) edge.second.second = i;
  }

  return ret;
}

bool solve() {
  edge.first = -INF;
  x = 0;

  for (int i = 0; i < n; i++) x ^= a[i];
  if (x == 0) return true;

  if (k == 2) return false;

  DFS(0);
  if (edge.first == -INF) return false;

  G[edge.second.first][edge.second.second] = -1;

  edge.first = -INF;
  DFS(0);
  return edge.first != -INF;
}

int main() {
  int t;
  aux = scanf("%d", &t);
  while (t--) {
    aux = scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) aux = scanf("%d", a + i);
    for (int i = 0; i < n - 1; i++) {
      int u, v;
      aux = scanf("%d%d", &u, &v);
      G[u - 1].push_back(v - 1);
      G[v - 1].push_back(u - 1);
    }

    (solve()) ? puts("YES") : puts("NO");

    for (int i = 0; i < n; i++) G[i].clear();
  }

  return 0;
}
