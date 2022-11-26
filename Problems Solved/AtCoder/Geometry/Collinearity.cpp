#include <cstdio>

int main() {
  int n;
  scanf("%d", &n);
  int x[n], y[n];
  for (int i = 0; i < n; i++) scanf("%d%d", x + i, y + i);

  bool can = false;

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      for (int z = j + 1; z < n; z++) {
        int m1 = (y[i] - y[j]) * (x[i] - x[z]);
        int m2 = (y[i] - y[z]) * (x[i] - x[j]);
        can |= (m1 == m2);
      }
    }
  }

  (can) ? puts("Yes") : puts("No");

  return 0;
}
