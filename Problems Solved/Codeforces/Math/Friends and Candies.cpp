#include <cstdio>

const int MAXN = 2e5;
int n, a[MAXN];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", a + i);

    int s = 0;
    for (int i = 0; i < n; i++) s += a[i];

    if (s % n != 0) {
      puts("-1");
      continue;
    }
    int ans = 0;

    for (int i = 0; i < n; i++)
      if (a[i] > s / n) ans++;

    printf("%d\n", ans);
  }

  return 0;
}
