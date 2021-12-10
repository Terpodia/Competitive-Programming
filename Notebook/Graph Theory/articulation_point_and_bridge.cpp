#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int aux;

enum { UNVISITED=-1, VISITED=-2 };

const int MAXN = 2e5;

vector<int> G[MAXN], dfs_num(MAXN, UNVISITED), dfs_low(MAXN), dfs_parent(MAXN);
bool articulation_vertex[MAXN];
int dfsNumberCounter, dfsRoot, rootChildren;

void DFS(int u) {
  dfs_num[u] = dfs_low[u] = dfsNumberCounter++;

  for (auto v : G[u]) {
    if (dfs_num[v] == UNVISITED) {
      dfs_parent[v] = u;
      if (u == dfsRoot) rootChildren++;
      DFS(v);
      
      if (dfs_low[v] >= dfs_num[u]) articulation_vertex[u] = true;
      if (dfs_low[v] > dfs_num[u]) printf("%d->%d\n", u, v);
      dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }

    else if (dfs_parent[u] != v)
      dfs_low[u] = min(dfs_low[u], dfs_num[v]);
  }
}

int main() {
  int n, m; aux=scanf("%d%d",&n,&m);
  for (int i=0; i<m; i++) {
    int u, v; aux=scanf("%d%d",&u,&v);
    G[u].push_back(v);
    G[v].push_back(u);
  }

  printf("Bridges\n");

  for (int i=0; i<n; i++) {
    if (dfs_num[i] == UNVISITED) {
      dfsRoot = i, rootChildren = 0;    
      dfs_parent[dfsRoot] = -1;
      DFS(i); 
      if (rootChildren <= 1) 
        articulation_vertex[dfsRoot] = false;
    }
  }

  printf("Articulation Points:\n");

  for (int i=0; i<n; i++)
    if (articulation_vertex[i])
      printf ("%d\n", i);

  return 0;
}

