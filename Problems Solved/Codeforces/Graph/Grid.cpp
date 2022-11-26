#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef tuple<int, int, int> tup;

const int xd[4] = {1, -1, 0, 0}, yd[4] = {0, 0, 1, -1};
const int MAXN = 500, INF = 1e9;
int n, m;
char a[MAXN][MAXN];

void fastIO() { cin.tie(0)->sync_with_stdio(0); }

bool can(int i, int j) { return (i >= 0 && j >= 0 && i < n && j < m); }

void solve() {
  vector<vi> dist(n, vi(m, INF));
  priority_queue<tup> pq;

  dist[0][0] = 0;
  pq.push(make_tuple(-0, 0, 0));

  while (!pq.empty()) {
    auto [p, i, j] = pq.top();
    pq.pop();

    p *= -1;
    if (dist[i][j] != p) continue;

    for (int _ = 0; _ < 4; _++) {
      int x = i + (xd[_] * (a[i][j] - '0'));
      int y = j + (yd[_] * (a[i][j] - '0'));

      if (!can(x, y)) continue;

      if (p + 1 < dist[x][y]) {
        dist[x][y] = p + 1;
        pq.push(make_tuple(-(p + 1), x, y));
      }
    }
  }

  (dist[n - 1][m - 1] != INF) ? cout << dist[n - 1][m - 1] << "\n"
                              : cout << "IMPOSSIBLE\n";
}

int main() {
  fastIO();

  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> a[i][j];

  solve();

  return 0;
}
