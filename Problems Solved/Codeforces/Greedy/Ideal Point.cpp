#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
      int l, r;
      cin >> l >> r;
      if (l <= k && k <= r) v.push_back({l, r});
    }
    if (v.empty())
      cout << "NO\n";
    else {
      bool can = true;
      for (int i = v[0].first; i <= v[0].second; i++) {
        if (i != k) {
          int cnt = 0;
          for (int j = 0; j < (int)v.size(); j++) {
            if (v[j].first <= i && i <= v[j].second) cnt++;
          }
          if (cnt == (int)v.size()) can = false;
        }
      }
      if (can)
        cout << "YES\n";
      else
        cout << "NO\n";
    }
  }
  return 0;
}
