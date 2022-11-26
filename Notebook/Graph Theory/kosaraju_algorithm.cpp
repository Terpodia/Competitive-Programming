#include <cstdio>
#include <cstring>
#include <stack>
#include <vector>
using namespace std;
int aux;

const int MAXN = 2e5;

vector<int> G[2][MAXN];
bool vis[MAXN];
stack<int> S;

void Kosaraju(int u, int pass = 1) {
  vis[u] = true;
  for (int v : G[pass][u])
    if (!vis[v]) {
      Kosaraju(v, pass);
    }
  if (pass == 1) S.push(u);
}

int main() {
  int n, m;
  aux = scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    int u, v;
    aux = scanf("%d%d", &u, &v);
    G[0][u].push_back(v);
    G[1][v].push_back(u);
  }

  for (int i = 0; i < n; i++)
    if (!vis[i]) Kosaraju(i);

  memset(vis, false, sizeof(vis));

  int cntSCC = 0;
  vector<int> SCC[MAXN];

  while (!S.empty()) {
    int u = S.top();
    S.pop();

    if (!vis[u]) {
      cntSCC++;
      Kosaraju(int u, 0);
    }
  }

  printf("%There are %d SCC in the directed graph\n", cntSCC);

  return 0;
}
