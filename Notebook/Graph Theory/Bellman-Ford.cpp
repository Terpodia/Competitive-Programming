// Bellman-Ford algorithm implementation

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int>> vvi;
typedef vector<int> vi;

int Bellman_Ford(vvi &edges, int n, int m, int s, int t) {
  vi d(n, 1e9);
  d[s] = 0;

  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < m; j++) {
      int u = edges[j][0];
      int v = edges[j][1];
      int w = edges[j][2];

      d[v] = min(d[v], d[u] + w);
    }
  }

  return d[t];
}

int main() {
  int n, m;
  cin >> n >> m;
  vvi edges(m, vi(3));

  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> v >> u >> w;
    edges[i][0] = v;
    edges[i][1] = u;
    edges[i][2] = w;
  }

  // Print the minimum distance between the nodes 0 and n-1
  cout << Bellman_Ford(edges, n, m, 0, n - 1) << "\n";

  return 0;
}
