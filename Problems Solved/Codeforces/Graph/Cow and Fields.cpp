#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef pair<int, int> ii;

#define FOR(i, x, n) for (int i = (x); i < (int)(n); i++)

const int MAXN = 2e5, INF = 1e9;

int n, m, k;
vector<int> G[MAXN];
pair<int, int> p[MAXN];

void fastIO() { cin.tie(0)->sync_with_stdio(0); }

vector<int> BFS(int s) {
  vector<bool> vis(n, false);
  vector<int> ret(n, INF);
  queue<ii> Q;
  Q.push(make_pair(s, 0));
  vis[s] = true;

  while (!Q.empty()) {
    auto& [u, w] = Q.front();
    Q.pop();
    ret[u] = w;

    for (int v : G[u])
      if (!vis[v]) {
        vis[v] = true;
        Q.push(make_pair(v, w + 1));
      }
  }

  return ret;
}

int main() {
  fastIO();
  cin >> n >> m >> k;

  int a[k];
  FOR(i, 0, k) cin >> a[i];

  FOR(i, 0, m) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }

  vector<int> dist[2];
  dist[0] = BFS(0);
  dist[1] = BFS(n - 1);

  int ans = 0;

  // min(x0 + y1, x1  + y0)
  // x0 + y1 <= x1 + y0
  // x0 - y0 <= x1 - y1
  // x0 - x1 <= y0 - y1

  FOR(i, 0, k) {
    p[i].first = dist[0][a[i] - 1] - dist[1][a[i] - 1];
    p[i].second = a[i] - 1;
  }

  sort(p, p + k);

  int hi = dist[0][p[0].second];

  FOR(i, 1, k) {
    ans = max(ans, hi + dist[1][p[i].second] + 1);
    hi = max(hi, dist[0][p[i].second]);
  }

  ans = min(ans, dist[0][n - 1]);
  cout << ans << "\n";

  return 0;
}
