#include <cstdio>

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, ai, c[3] = {0};
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d", &ai);
      c[ai % 3]++;
    }
    int ans = 0;

    for (int j = 0; j < 2; j++) {
      for (int i = 0; i < 3; i++) {
        if (c[i] > n / 3) {
          ans += c[i] - n / 3;
          c[(i + 1) % 3] += c[i] - n / 3;
          c[i] = n / 3;
        }
      }
    }

    printf("%d\n", ans);
  }

  return 0;
}
