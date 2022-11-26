#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int INF = 1e9;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int m;
    scanf("%d", &m);
    int a[2][m];
    for (int i = 0; i < 2; i++)
      for (int j = 0; j < m; j++) scanf("%d", a[i] + j);

    int pref[2][m + 1];
    memset(pref, 0, sizeof(pref));

    for (int i = 0; i < 2; i++) {
      for (int j = 1; j <= m; j++) {
        pref[i][j] = pref[i][j - 1] + a[i][j - 1];
      }
    }

    int ans = INF;

    for (int i = 1; i <= m; i++) {
      // int cnt = pref[0][i] + pref[1][m] - pref[1][i-1];
      int cnt = max(pref[1][i - 1], pref[0][m] - pref[0][i]);

      ans = min(ans, cnt);
    }

    printf("%d\n", ans);
  }

  return 0;
}
