#include <cstdio>

int main() {
  int n;
  scanf("%d", &n);
  int a[n];
  for (int i = 0; i < n; i++) scanf("%d", a + i);

  printf("%d\n", n + 1);
  printf("1 %d %d\n", n, (int)1e5);

  for (int i = 0; i < n; i++)
    printf("2 %d %d\n", i + 1, a[i] + (int)1e5 - (i + 1));

  return 0;
}
