#include <algorithm>
#include <cstring>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

typedef long long ll;

const ll INF = 1e18;

int N;
ll G[100][100];

unordered_map<int, string> mp;

void floyd_warshall(vector<vector<ll>>& dist) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (i == j)
        dist[i][i] = G[i][j];
      else if (G[i][j] != 0)
        dist[i][j] = G[i][j];  // If there is an edge, set distance to the
                               // weight of that edge
    }
  }

  for (int k = 0; k < N; k++) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (dist[i][k] < INF && dist[k][j] < INF &&
            dist[k][k] < 0)  // There is a negative cycle
          dist[i][j] = -INF;

        else if (dist[i][k] < INF && dist[k][j] < INF)
          dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int t = 1;

  while (cin >> N &&
         N != 0) {  // N = number of vertices, N = 0 means end of the input
    for (int i = 0; i < N; i++) {  // for each node
      string s;
      cin >> s;  // read his name
      mp[i] = s;

      for (int j = 0; j < N; j++) {
        ll w;
        cin >> w;     // Distance from the node i to every other node including
                      // himself
        G[i][j] = w;  // If w = 0, the edge doesn't exist
      }
    }

    // Distance for every pair of nodes
    // If dist[i][j] = -INF, then ther is a negative cycle in the path from node
    // i to node j
    vector<vector<ll>> dist(N, vector<ll>(N, INF));

    floyd_warshall(dist);  // Precompute all distance

    cout << "Case #" << t++ << ":\n";

    int Q;
    cin >> Q;  // Number of queries

    while (Q--) {
      int u, v;
      cin >> u >> v;

      if (dist[u][v] == INF)
        cout << mp[u] << "-" << mp[v] << " NOT REACHABLE\n";

      else if (dist[u][v] == -INF)
        cout << "NEGATIVE CYCLE\n";

      else
        cout << mp[u] << "-" << mp[v] << " " << dist[u][v] << "\n";
    }

    // Restarting global variables
    memset(G, 0, sizeof(G));
    mp.clear();
  }

  return 0;
}
