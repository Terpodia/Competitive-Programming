#include <algorithm>
#include <fstream>
#include <iostream>
using namespace std;

const int INF = 1e9;

struct pos {
  int x, y;
  int dist(int x2, int y2) { return (x - x2) * (x - x2) + (y - y2) * (y - y2); }
  pos operator+(pos p) { return {x + p.x, y + p.y}; }
};

int main() {
  ifstream fin("radio.in");
  ofstream fout("radio.out");

  int N, M;
  pos f, b;
  fin >> N >> M;
  fin >> f.x >> f.y;
  fin >> b.x >> b.y;

  pos path1[N], path2[M];
  for (int i = 0; i < N; i++) {
    char c;
    fin >> c;
    if (c == 'N')
      path1[i] = {0, 1};
    else if (c == 'S')
      path1[i] = {0, -1};
    else if (c == 'E')
      path1[i] = {1, 0};
    else
      path1[i] = {-1, 0};
  }

  for (int i = 0; i < M; i++) {
    char c;
    fin >> c;
    if (c == 'N')
      path2[i] = {0, 1};
    else if (c == 'S')
      path2[i] = {0, -1};
    else if (c == 'E')
      path2[i] = {1, 0};
    else
      path2[i] = {-1, 0};
  }

  int dp[N + 1][M + 1];
  for (int i = 0; i <= N; i++)
    for (int j = 0; j <= M; j++) dp[i][j] = INF;
  dp[0][0] = 0;

  pos gj = f, bessie = b;

  for (int i = 1; i <= N; i++) {
    gj = gj + path1[i - 1];
    dp[i][0] = gj.dist(b.x, b.y) + dp[i - 1][0];
  }

  for (int i = 1; i <= M; i++) {
    bessie = bessie + path2[i - 1];
    dp[0][i] = bessie.dist(f.x, f.y) + dp[0][i - 1];
  }

  for (int i = 1; i <= N; i++) {
    gj = f, bessie = b;
    for (int j = 0; j < i; j++) gj = gj + path1[j];

    for (int j = 1; j <= M; j++) {
      bessie = bessie + path2[j - 1];
      int d = gj.dist(bessie.x, bessie.y);
      dp[i][j] =
          min(dp[i - 1][j - 1] + d, min(dp[i - 1][j] + d, dp[i][j - 1] + d));
    }
  }

  fout << dp[N][M] << "\n";

  return 0;
}
