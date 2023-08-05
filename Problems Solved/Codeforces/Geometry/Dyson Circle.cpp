#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 8;

int main() {
  int n;
  scanf("%d", &n);
  int x[n], y[n];
  for (int i = 0; i < n; i++) scanf("%d%d", &x[i], &y[i]);
  bool same_diagonal = true;
  for (int i = 1; i < n; i++) {
    same_diagonal &= (abs(x[i] - x[0]) == abs(y[i] - y[0]));
  }
  if (n == 1)
    puts("4");
  else {
    int a, b, c, d;
    a = b = c = d = -INF;
    for (int i = 0; i < n; i++) {
      a = max(a, x[i] + y[i]);
      b = max(b, x[i] - y[i]);
      c = max(c, -x[i] + y[i]);
      d = max(d, -x[i] - y[i]);
    }
    int ans = a + b + c + d + 4;
    if (same_diagonal) ans++;
    printf("%d\n", ans);
  }
  return 0;
}
