#include <algorithm>
#include <cstring>
#include <fstream>
#include <iostream>
using namespace std;

struct point {
  int x, y;
};

const int MAXN = 1007, INF = 1e9;
int H, G, dp[MAXN][MAXN][2];
point h[MAXN], g[MAXN];

int dist(point p1, point p2) {
  return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

int solve(int i, int j, int c) {
  if (i >= H - 1 && j < G - 1) return INF;
  if (i >= H - 1 && j >= G - 1) return 0;
  int& ret = dp[i][j + 1][c];
  if (ret != -1) return ret;

  point p;
  (c == 0) ? p = h[i] : p = g[j];
  if (j >= G - 1) return ret = solve(i + 1, j, 0) + dist(h[i + 1], p);

  return ret = min(solve(i + 1, j, 0) + dist(h[i + 1], p),
                   solve(i, j + 1, 1) + dist(g[j + 1], p));
}

int main() {
  memset(dp, -1, sizeof(dp));
  ifstream fin("checklist.in");
  ofstream fout("checklist.out");
  fin >> H >> G;
  for (int i = 0; i < H; i++) fin >> h[i].x >> h[i].y;
  for (int i = 0; i < G; i++) fin >> g[i].x >> g[i].y;

  int ans = solve(0, -1, 0);
  fout << ans << "\n";

  return 0;
}
