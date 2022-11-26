// Dijkstra algorithm implementation
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define forn(i, x, n) for (int i = (x); i < (int)(n); i++)
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> ii;

// Dijkstra algorithm
int Dijkstra(vvi &G, vvi &W, int s, int t, int n) {
  vi dist(n, 1e9);  // Initializing distance vector to infinity
  priority_queue<ii> Q;

  Q.push({-0, s});
  dist[s] = 0;  // The distance from a node to itself is 0

  while (!Q.empty()) {
    ii arc = Q.top();
    Q.pop();

    int v = arc.second;
    int p = arc.first;
    p *= -1;

    if (dist[v] != p) continue;

    forn(i, 0, G[v].size()) {
      int u = G[v][i];
      int w = W[v][i];

      if (w + p < dist[u]) {
        dist[u] = w + p;
        Q.push({-dist[u], u});
      }
    }
  }

  return dist[t];  // Minimum distance from S to T
}

int main() {
  int n, m;  // number of vertices and edges in the graph
  cin >> n >> m;
  vvi G(n), W(n);

  forn(i, 0, m) {
    int u, v, w;  // edge from u to v with weight w
    cin >> u >> v >> w;

    G[u].push_back(v);
    G[v].push_back(u);
    W[u].push_back(w);
    W[v].push_back(w);
  }

  cout << Dijkstra(G, W, 0, n - 1, n)
       << "\n";  // Print the shortest path between nodes 0 and n-1

  return 0;
}
