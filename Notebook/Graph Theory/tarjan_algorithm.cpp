#include <cstdio>
#include <stack>
#include <vector>
using namespace std;
int aux;

enum { UNVISITED = -1, VISITED = -2 }

const int MAXN = 2e5;

vector<int> G[MAXN], dfs_num(MAXN, UNVISITED), dfs_low(MAXN);
bool vis[MAXN];
int cntSCC, dfsNumberCounter;
stack<int> S;

void Tarjan(int u) {
  S.push(u);
  dfs_num[u] = dfs_low[u] = dfsNumberCounter++;
  vis[u] = true;

  for (int v : G[u]) {
    if (dfs_num[v] == UNVISITED) 
      Tarjan(v);
    if (vis[v])
      dfs_low[u] = min(dfs_low[u], dfs_low[v]);
  }

  if (dfs_low[u] == dfs_num[u]) {
    cntSCC++;
    printf("SCC: [ ");
    while (!S.empty()) {
      int v = S.top(); S.pop();
      vis[v] = false;
      printf("%d ", v);
      if (u == v) break;
    }
    printf("]\n");
  }
}

int main() {
  int n, m; aux=scanf("%d",&n,&m);
  for (int i=0; i<m; i++) {
    int u, v; aux=scanf("%d%d",&u,&v);
    G[u].push_back(v);
  }
  
  for (int i=0; i<n; i++) {
    if (dfs_num[i] == UNVISITED)  
      Tarjan(i);
  }

  return 0;
}

