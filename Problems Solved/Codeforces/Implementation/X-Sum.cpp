#include <algorithm>
#include <cstdio>
using namespace std;

const int INF = 1e9;

int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n, m;
    scanf("%d%d", &n, &m);
    int a[n][m];
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) scanf("%d", &a[i][j]);

    int s1[n + m], s2[n + m], id1[n][m], id2[n][m];

    for (int i = 0; i < n; i++) {
      int s = 0;
      for (int j = 0; j < m && i + j < n; j++)
        s += a[i + j][j], id1[i + j][j] = i;
      s1[i] = s;
    }
    for (int j = 0; j < m; j++) {
      int s = 0;
      for (int i = 0; i < n && j + i < m; i++)
        s += a[i][j + i], id1[i][j + i] = j + n;
      s1[j + n] = s;
    }
    for (int i = 0; i < n; i++) {
      int s = 0;
      for (int j = 0; j < m && i + j < n; j++)
        s += a[i + j][m - 1 - j], id2[i + j][m - 1 - j] = i;
      s2[i] = s;
    }
    for (int j = 0; j < m; j++) {
      int s = 0;
      for (int i = 0; i < n && j + i < m; i++)
        s += a[i][m - 1 - j - i], id2[i][m - 1 - j - i] = j + n;
      s2[j + n] = s;
    }
    int ans = -INF;

    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        ans = max(ans, s1[id1[i][j]] + s2[id2[i][j]] - a[i][j]);

    printf("%d\n", ans);
  }
  return 0;
}
