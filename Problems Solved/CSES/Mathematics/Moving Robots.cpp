#include "bits/stdc++.h"
using namespace std;

#define fst first
#define snd second

typedef long double ld;

pair<int, int> dest;

const int rm[] = {1, -1, 0, 0}, cm[] = {0, 0, 1, -1};

ld dp[8][8][101];

ld solve(int i, int j, int k) {
  if (k == 0) {
    if (i != dest.fst || j != dest.snd) return 0;
    return 1;
  }
  ld& ret = dp[i][j][k];

  if (ret >= 0) return ret;

  ret = 0;

  for (int _ = 0; _ < 4; _++) {
    int r = i + rm[_], c = j + cm[_];
    if (r < 0 || c < 0 || r >= 8 || c >= 8) continue;

    int tot = 0;

    for (int __ = 0; __ < 4; __++) {
      int rr = r + rm[__], cc = c + cm[__];
      if (rr < 0 || cc < 0 || rr >= 8 || cc >= 8) continue;
      tot++;
    }

    ret += solve(r, c, k - 1) / (ld)tot;
  }
  return ret;
}

int main() {
  int k;
  scanf("%d", &k);

  ld ans[8][8];
  for (int i = 0; i < 8; i++)
    for (int j = 0; j < 8; j++) ans[i][j] = 1;

  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      for (int r = 0; r < 8; r++)
        for (int c = 0; c < 8; c++)
          for (int w = 0; w <= k; w++) dp[r][c][w] = -1;

      dest = {i, j};
      for (int r = 0; r < 8; r++) {
        for (int c = 0; c < 8; c++) {
          ans[r][c] *= (ld)1 - solve(r, c, k);
        }
      }
    }
  }
  ld res = 0;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      res += ans[i][j];
    }
  }
  printf("%.6Lf\n", res);
  return 0;
}
