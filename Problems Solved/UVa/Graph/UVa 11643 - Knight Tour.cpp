#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;
int aux;

typedef vector<int> vi;
typedef vector<vi> vvi;

const int dr[8] = {2, 2, 1, 1, -2, -2, -1, -1},
          dc[8] = {1, -1, 2, -2, 1, -1, 2, -2}, INF = 1e9;

int n, k, p[16][2], dp[16][1 << 16], it = 0;
vvi dist(16, vi(16));
vvi d, curr;

vvi bfs_pre() {
  d[0][0] = 0;
  queue<tuple<int, int, int>> q;
  q.push({0, 0, 0});

  while (!q.empty()) {
    auto [ur, uc, w] = q.front();
    q.pop();

    for (int i = 0; i < 8; i++) {
      int vr = dr[i] + ur, vc = dc[i] + uc;
      if (vr < 0 || vc < 0 || vr >= n || vc >= n || d[vr][vc] != -1) continue;
      d[vr][vc] = w + 1;
      q.push({vr, vc, w + 1});
    }
  }
  return d;
}

int bfs(pair<int, int> s, pair<int, int> t) {
  d[s.first][s.second] = 0;
  curr[s.first][s.second] = it;

  queue<tuple<int, int, int>> q;
  q.push({s.first, s.second, 0});

  while (!q.empty()) {
    auto [ur, uc, w] = q.front();
    q.pop();

    if (ur == t.first && uc == t.second) return d[ur][uc];

    for (int i = 0; i < 8; i++) {
      int vr = dr[i] + ur, vc = dc[i] + uc;
      if (vr < 0 || vc < 0 || vr >= n || vc >= n || curr[vr][vc] == it)
        continue;

      d[vr][vc] = w + 1;
      curr[vr][vc] = it;
      q.push({vr, vc, w + 1});

      if (vr == t.first && vc == t.second) return d[vr][vc];
    }
  }
  return -1;
}

int f(int i, int msk) {
  if (__builtin_popcount(msk) == k) return dp[i][msk] = dist[i][0];
  int& ret = dp[i][msk];
  if (ret != -1) return ret;

  ret = INF;

  for (int j = 0; j < k; j++) {
    if ((msk & (1 << j)) == 0) {
      ret = min(ret, dist[i][j] + f(j, msk | (1 << j)));
    }
  }

  return ret;
}

void solve(int tc) {
  d = vvi(n, vi(n, -1));
  vvi dist_pre(n, vi(n));
  dist_pre = bfs_pre();

  d = vvi(n, vi(n, -1));
  curr = vvi(n, vi(n, 0));
  it = 0;

  for (int i = 0; i < k; i++) {
    for (int j = 0; j < k; j++) {
      int diff_r = abs(p[i][0] - p[j][0]);
      int diff_c = abs(p[i][1] - p[j][1]);

      if (diff_r + diff_c >= 3)
        dist[i][j] = dist_pre[diff_r][diff_c];
      else {
        it++;
        int v = bfs(make_pair(p[i][0], p[i][1]), make_pair(p[j][0], p[j][1]));
        dist[i][j] = (v != -1) ? v : dist_pre[diff_r][diff_c];
      }
    }
  }

  memset(dp, -1, sizeof(dp));

  printf("Case %d: %d\n", tc, f(0, 1));
}

int main() {
  int TC;
  aux = scanf("%d", &TC);
  for (int _ = 1; _ <= TC; _++) {
    aux = scanf("%d%d", &n, &k);
    for (int i = 0; i < k; i++) {
      aux = scanf("%d%d", &p[i][0], &p[i][1]);
      p[i][0]--, p[i][1]--;
    }

    solve(_);
  }

  return 0;
}
