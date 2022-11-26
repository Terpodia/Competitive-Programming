#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 1e5;

int n;
vector<int> G[MAXN], colors(MAXN, 0);

void DFS(int u, int c) {
  colors[u] = c;
  int next_color = (c == 2) ? 3 : 2;

  for (int v : G[u]) {
    if (!colors[v]) DFS(v, next_color);
  }
}

int main() {
  int q;
  scanf("%d%d", &n, &q);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    G[u - 1].push_back(v - 1);
    G[v - 1].push_back(u - 1);
  }

  DFS(0, 1);

  while (q--) {
    int c, d;
    scanf("%d%d", &c, &d);
    c--, d--;
    if (c == 0)
      (colors[d] == 3) ? puts("Town") : puts("Road");
    else
      (colors[c] == colors[d]) ? puts("Town") : puts("Road");
  }

  return 0;
}
