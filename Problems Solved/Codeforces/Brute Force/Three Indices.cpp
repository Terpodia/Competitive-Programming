#include <cstdio>

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    int p[n];
    for (int i = 0; i < n; i++) scanf("%d", p + i);

    bool can = false;
    int ans[3];

    for (int i = 1; i < n - 1; i++) {
      int x, y;
      x = y = -1;

      for (int j = i - 1; j >= 0; j--) {
        if (p[j] < p[i]) x = j;
      }

      for (int j = i + 1; j < n; j++) {
        if (p[j] < p[i]) y = j;
      }

      if (x != -1 && y != -1) {
        ans[0] = x + 1, ans[1] = i + 1, ans[2] = y + 1;
        can = true;
      }
    }

    if (can) {
      puts("YES");
      printf("%d %d %d\n", ans[0], ans[1], ans[2]);
    } else
      puts("NO");
  }

  return 0;
}
