#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 800, INF = 1e9 + 7;
int k, n, a[MAXN][MAXN];

vector<vector<int>> build_psum2D(int x) {
  vector<vector<int>> ret(n + 1, vector<int>(n + 1, 0)), b(n, vector<int>(n));
  ;

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) b[i][j] = (a[i][j] <= x) ? 1 : 0;

  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      ret[i][j] =
          ret[i - 1][j] + ret[i][j - 1] - ret[i - 1][j - 1] + b[i - 1][j - 1];

  return ret;
}

int query(int r1, int c1, int r2, int c2, vector<vector<int>>& psum2D) {
  return psum2D[r2][c2] - psum2D[r2][c1 - 1] - psum2D[r1 - 1][c2] +
         psum2D[r1 - 1][c1 - 1];
}

bool can(int x) {
  vector<vector<int>> psum2D = build_psum2D(x);

  for (int i = 0; i + k - 1 < n; i++) {
    for (int j = 0; j + k - 1 < n; j++) {
      if (query(i + 1, j + 1, i + k, j + k, psum2D) >= (k * k + 1) / 2)
        return true;
    }
  }

  return false;
}

int solve() {
  int l = 0, r = INF, ret = -1;

  while (r >= l) {
    int mid = l + (r - l) / 2;
    if (can(mid)) {
      ret = mid;
      r = mid - 1;
    } else
      l = mid + 1;
  }

  return ret;
}

int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) scanf("%d", &a[i][j]);

  printf("%d\n", solve());

  return 0;
}
