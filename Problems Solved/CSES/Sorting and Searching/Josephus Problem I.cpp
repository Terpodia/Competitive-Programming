#include <cstdio>

int main() {
  int n;
  scanf("%d", &n);
  bool a[n];
  for (int i = 0; i < n; i++) a[i] = true;
  int cnt = n, j = 0;
  while (cnt > 0) {
    while (!a[j]) j = (j + 1) % n;
    j = (j + 1) % n;
    while (!a[j]) j = (j + 1) % n;
    printf("%d ", j + 1);
    a[j] = false, cnt--;
  }
  return 0;
}
