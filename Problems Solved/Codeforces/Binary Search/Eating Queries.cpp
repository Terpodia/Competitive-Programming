#include <bits/stdc++.h>
using namespace std;

int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n, q;
    scanf("%d%d", &n, &q);
    int a[n];
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    sort(a, a + n, greater<int>());
    vector<int> pref(n + 1, 0);
    for (int i = 1; i <= n; i++) pref[i] = pref[i - 1] + a[i - 1];
    while (q--) {
      int x;
      scanf("%d", &x);
      int d = distance(pref.begin(), lower_bound(pref.begin(), pref.end(), x));
      printf("%d\n", (d <= n) ? d : -1);
    }
  }
  return 0;
}
