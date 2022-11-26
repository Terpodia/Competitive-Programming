#include <cstdio>

int main() {
  int t;
  scanf("%d", &t);

  while (t--) {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    (n * m - 1 == k) ? puts("YES") : puts("NO");
  }

  return 0;
}
