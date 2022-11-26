#include <algorithm>
#include <iostream>
using namespace std;

void fastIO() { cin.tie(0)->sync_with_stdio(0); }

int main() {
  fastIO();

  int t;
  cin >> t;

  while (t--) {
    int n, m, x, y;
    cin >> n >> m >> x >> y;

    string a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    int ans = 0;

    for (int i = 0; i < n; i++) {
      int cnt = 0;
      for (int j = 0; j < m; j++) {
        if (a[i][j] == '.')
          cnt++;
        else {
          ans += (cnt % 2) * x;
          if (cnt % 2 != 0) cnt--;
          ans += min(cnt / 2 * y, cnt * x);
          cnt = 0;
        }
      }

      if (cnt != 0) {
        ans += (cnt % 2) * x;
        if (cnt % 2 != 0) cnt--;
        ans += min(cnt / 2 * y, cnt * x);
      }
    }

    cout << ans << "\n";
  }

  return 0;
}
