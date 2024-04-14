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
    int m = min(n, k);
    int acc = 0;

    bool can = true;

    while (m > 0) {
      int p = n - 1 - acc;
      p %= n, p += n, p %= n;

      if (a[p] > n) {
        can = false;
        break;
      }
      acc += a[p];
      acc %= n;

      m--;
    }

    printf("%s\n", (can) ? "Yes" : "No");
  }
  return 0;
}
