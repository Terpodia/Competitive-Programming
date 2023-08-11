#include <algorithm>
#include <cstdio>
using namespace std;

int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    char a[n][n];
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) scanf(" %c", &a[i][j]);
    int ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        int cnt1 = 0, cnt2 = 0;
        (a[i][j] == '1') ? cnt1++ : cnt2++;
        (a[j][n - 1 - i] == '1') ? cnt1++ : cnt2++;
        (a[n - 1 - i][n - 1 - j] == '1') ? cnt1++ : cnt2++;
        (a[n - 1 - j][i] == '1') ? cnt1++ : cnt2++;

        ans += min(cnt1, cnt2);
      }
    }
    ans /= 4;
    printf("%d\n", ans);
  }
  return 0;
}
