#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 10;

int nxt[MAXN][31];

int main() {
  int n, q;
  scanf("%d%d", &n, &q);
  for (int i = 0; i < n; i++) {
    scanf("%d", &nxt[i][0]);
    nxt[i][0]--;
  }
  for (int i = 1; i < 30; i++) {
    for (int j = 0; j < n; j++) {
      nxt[j][i] = nxt[nxt[j][i - 1]][i - 1];
    }
  }
  while (q--) {
    int x, k;
    scanf("%d%d", &x, &k);
    int ans = x - 1;
    for (int i = 30; i >= 0; i--) {
      int a = (1 << i);
      if (k - a >= 0) {
        k -= a;
        ans = nxt[ans][i];
      }
    }
    printf("%d\n", ans + 1);
  }
  return 0;
}
