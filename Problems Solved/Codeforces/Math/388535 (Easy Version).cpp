#include <cstdio>
#include <cstring>

int s[131072][17];

int main() {
  for (int i = 1; i < 131072; i++) {
    for (int j = 0; j < 17; j++) {
      s[i][j] = s[i - 1][j];
      if (i & (1 << j)) s[i][j]++;
    }
  }
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int l, r;
    scanf("%d%d", &l, &r);
    int a[r + 1];
    for (int i = 0; i <= r; i++) scanf("%d", a + i);
    int ans = 0;
    for (int j = 0; j < 17; j++) {
      int cnt = 0;
      for (int i = 0; i < r - l + 1; i++) {
        if (a[i] & (1 << j)) cnt++;
      }
      if (cnt != s[r][j]) ans |= 1 << j;
    }
    printf("%d\n", ans);
  }
  return 0;
}

