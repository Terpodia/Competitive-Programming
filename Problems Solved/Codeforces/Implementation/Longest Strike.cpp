#include <bits/stdc++.h>
using namespace std;

int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n, k;
    scanf("%d%d", &n, &k);
    int a[n];
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    map<int, int> mp;
    for (int i = 0; i < n; i++) mp[a[i]]++;
    sort(a, a + n);
    int i = 0, l = -1, r = -1;
    while (i < n) {
      if (mp[a[i]] < k) {
        i++;
        continue;
      }
      int lx = a[i], rx = a[i];
      while (i + 1 < n && a[i + 1] - a[i] <= 1) {
        if (a[i + 1] == a[i])
          i++;
        else if (mp[a[i + 1]] >= k)
          rx++, i++;
        else
          break;
      }
      if (l == -1)
        l = lx, r = rx;
      else if (r - l < rx - lx)
        l = lx, r = rx;
      i++;
    }
    if (l == -1)
      printf("-1\n");
    else
      printf("%d %d\n", l, r);
  }
  return 0;
}
