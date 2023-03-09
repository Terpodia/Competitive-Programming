#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    int a[4 * n];
    for (int i = 0; i < 4 * n; i++) cin >> a[i];
    map<int, int> cnt;
    for (int i = 0; i < 4 * n; i++) cnt[a[i]]++;
    bool can = true;
    for (int i = 0; i < 4 * n; i++) can &= cnt[a[i]] % 2 == 0;
    if (!can)
      cout << "NO\n";
    else {
      can = false;
      for (auto& [i, c] : cnt) {
        bool flag = true;
        int x = a[0] * i;
        for (auto& [j, k] : cnt) {
          if (!flag) break;
          flag &= (x % j) == 0;
          if (cnt.find(x / j) == cnt.end())
            flag = false;
          else
            flag &= cnt[x / j] == k;
        }
        can |= flag;
      }
      if (!can)
        cout << "NO\n";
      else
        cout << "YES\n";
    }
  }
  return 0;
}
