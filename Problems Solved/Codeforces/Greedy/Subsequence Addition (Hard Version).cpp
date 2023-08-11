#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    int c[n];
    for (int i = 0; i < n; i++) cin >> c[i];
    sort(c, c + n);
    bool can = true;
    if (c[0] != 1) can = false;
    int s = 1;
    for (int i = 1; i < n; i++) {
      if (s < c[i]) {
        can = false;
        break;
      }
      s = min(s + c[i], (int)1e7);
    }
    (can) ? cout << "YES\n" : cout << "NO\n";
  }
  return 0;
}
