#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, q;
  scanf("%d%d", &n, &q);
  int a[n];
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  int c[n];
  for (int i = 0; i < n; i++) c[a[i] - 1] = i;

  int ans = 0;
  for (int i = 0; i < n - 1; i++) {
    if (c[i] > c[i + 1]) ans++;
  }

  while (q--) {
    int i, j, ai, aj;
    scanf("%d%d", &i, &j);
    i--, j--;
    if (a[i] > a[j]) swap(i, j);
    ai = a[i] - 1, aj = a[j] - 1;
    /*
    printf("%d %d\n", a[i], a[j]);
    printf("%d %d\n", ai, aj);
    printf("%d %d\n", c[ai], c[aj]);
    puts("...........................\n");
    */

    if (ai < n - 1 && c[ai] > c[ai + 1]) ans--;
    if (aj < n - 1 && c[aj] > c[aj + 1]) ans--;
    if (ai > 0 && c[ai] < c[ai - 1]) ans--;
    if (a[j] - a[i] > 1 && aj > 0 && c[aj] < c[aj - 1]) ans--;

    swap(c[ai], c[aj]);
    swap(a[i], a[j]);
    swap(i, j);

    if (ai < n - 1 && c[ai] > c[ai + 1]) ans++;
    if (aj < n - 1 && c[aj] > c[aj + 1]) ans++;
    if (ai > 0 && c[ai] < c[ai - 1]) ans++;
    if (a[j] - a[i] > 1 && aj > 0 && c[aj] < c[aj - 1]) ans++;

    printf("%d\n", ans + 1);
  }
  return 0;
}
