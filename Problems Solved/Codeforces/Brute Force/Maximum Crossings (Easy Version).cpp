#include <cstdio>

int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) scanf("%d", a + i);

    int ans = 0;
    for (int i = 1; i < n; i++) {
      for (int j = i - 1; j >= 0; j--) {
        if (a[i] <= a[j]) ans++;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
