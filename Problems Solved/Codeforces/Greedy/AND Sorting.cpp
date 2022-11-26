#include <bits/stdc++.h>
using namespace std;

int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    int p[n];
    for (int i = 0; i < n; i++) scanf("%d", p + i);
    int ans = (1 << 20) - 1;

    for (int i = 0; i < n; i++) {
      if (i != p[i]) ans &= p[i];
    }
    printf("%d\n", ans);
  }
  return 0;
}
