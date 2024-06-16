#include <cstdio>

int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n, m;
    scanf("%d%d", &n, &m);
    if (n >= m && (n - m) % 2 == 0)
      puts("YES");
    else
      puts("NO");
  }
  return 0;
}
