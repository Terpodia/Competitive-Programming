#include <cstdio>

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    printf("%d\n", !(n % 2));
  }
  return 0;
}
