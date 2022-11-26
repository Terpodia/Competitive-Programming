#include <deque>
#include <iostream>
#include <vector>
using namespace std;
using vi = vector<int>;
using pi = pair<int, int>;

#define mp make_pair

const int MAXN = 1e3, INF = 1e9;
const int xd[] = {1, -1, 0, 0}, yd[] = {0, 0, 1, -1};

int n, m, ch, cw, dh, dw;
char a[MAXN][MAXN];

void fastIO() { cin.tie(0)->sync_with_stdio(false); }

bool can(int i, int j) {
  return (i < n && j < m && i >= 0 && j >= 0 && a[i][j] == '.');
}

int solve() {
  vector<vi> dist(n, vi(m, INF));
  deque<pair<pi, int>> dq;
  dq.push_back(mp(mp(ch, cw), 0));
  dist[ch][cw] = 0;

  while (!dq.empty()) {
    pi pos = dq.front().first;
    int p = dq.front().second;
    dq.pop_front();

    if (p != dist[pos.first][pos.second]) continue;

    for (int _ = 0; _ < 4; _++) {
      int i = pos.first + xd[_], j = pos.second + yd[_];
      if (!can(i, j)) continue;

      if (dist[i][j] > p) {
        dist[i][j] = p;
        dq.push_front(mp(mp(i, j), p));
      }
    }

    for (int _ = -2; _ <= 2; _++) {
      for (int __ = -2; __ <= 2; __++) {
        int i = pos.first + _, j = pos.second + __;
        if (!can(i, j)) continue;
        if (dist[i][j] > p + 1) {
          dist[i][j] = p + 1;
          dq.push_back(mp(mp(i, j), p + 1));
        }
      }
    }
  }

  return (dist[dh][dw] < INF) ? dist[dh][dw] : -1;
}

int main() {
  fastIO();

  cin >> n >> m;
  cin >> ch >> cw >> dh >> dw;

  ch--, cw--, dh--, dw--;

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> a[i][j];

  cout << solve() << "\n";

  return 0;
}
