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

    if (n % 2 == 0)
      puts("YES");
    else {
      bool can = false;
      for (int i = 0; i < n - 1; i++)
        if (a[i] >= a[i + 1]) can = true;

      (can) ? puts("YES") : puts("NO");
    }
  }

  return 0;
}
