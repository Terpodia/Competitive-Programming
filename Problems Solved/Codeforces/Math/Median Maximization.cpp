#include <cstdio>
int aux;

int main() {
  int t;
  aux = scanf("%d", &t);
  while (t--) {
    int n, s;
    aux = scanf("%d%d", &n, &s);
    int d = (n + 1) / 2;

    int ans = s / (n - (d - 1));
    printf("%d\n", ans);
  }

  return 0;
}
