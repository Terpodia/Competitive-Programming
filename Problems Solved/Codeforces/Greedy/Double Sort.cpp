#include <bits/stdc++.h>
using namespace std;

int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < n; i++) scanf("%d", &b[i]);
    c = b;
    sort(c.begin(), c.end());

    vector<pair<int, int>> ans;

    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (a[i] > a[j]) {
          ans.push_back({i + 1, j + 1});
          swap(a[i], a[j]);
          swap(b[i], b[j]);
        }
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (b[i] > b[j] && a[i] == a[j]) {
          ans.push_back({i + 1, j + 1});
          swap(a[i], a[j]);
          swap(b[i], b[j]);
        }
      }
    }
    if (b != c)
      printf("-1\n");
    else {
      printf("%d\n", (int)ans.size());
      for (auto &[x, y] : ans) printf("%d %d\n", x, y);
    }
  }
  return 0;
}
