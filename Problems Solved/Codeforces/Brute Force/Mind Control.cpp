#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 6;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m, k;
    cin >> n >> m >> k;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    int ans = -INF;

    k = min(k, m - 1);
    for (int x = 0; x <= k; x++) {
      int res = INF;
      for (int y = 0; y <= m - k - 1; y++) {
        res = min(res, max(a[x + y], a[n - m + x + y]));
      }
      ans = max(ans, res);
    }
    cout << ans << "\n";
  }
  return 0;
}
