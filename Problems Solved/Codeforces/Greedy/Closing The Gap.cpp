#include <cstdio>
int aux;

int main() {
  int t;
  aux = scanf("%d", &t);
  while (t--) {
    int n;
    aux = scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) aux = scanf("%d", a + i);

    int s = 0;
    for (int i = 0; i < n; i++) s += a[i];

    if (s % n == 0)
      puts("0");
    else
      puts("1");
  }

  return 0;
}
