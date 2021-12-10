// Floyd-Warshall algorithm implementation

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<vector<int>> vvi;
typedef vector<int> vi;

void Floyd_Warshall(vvi &G, vvi &dist, int n) {
    dist = G;

    for(int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j && dist[i][j] == 0) dist[i][j] = 1e9;
        }
    }
  
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int main() {
    int n, m; cin >> n >> m;

    vvi G(n, vi(n, 0)), dist;

    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u][v] = G[v][u] = w;
    }

    Floyd_Warshall(G, dist, n);

    // Printing the Minimum Distance between every pair of nodes

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << dist[i][j] << "\n";
        }
    }

  return 0;
}
