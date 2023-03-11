#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    int pref[n + 1], suff[n + 1];
    pref[0] = 1, suff[n] = 1;
    for (int i = 1; i <= n; i++) {
      pref[i] = pref[i - 1];
      if (a[i - 1] < i - 1) pref[i] = 0;
    }
    for (int i = n - 1; i >= 0; i--) {
      suff[i] = suff[i + 1];
      if (a[i] < n - i - 1) {
        suff[i] = 0;
      }
    }
    bool can = false;
    for (int i = 0; i < n; i++) {
      if (pref[i] == 0 || suff[i + 1] == 0) continue;
      can |= (i - 1 <= a[i] - 1 && n - i - 2 <= a[i] - 1);
    }
    if (!can)
      cout << "No\n";
    else
      cout << "Yes\n";
  }
  return 0;
}
