#include <cstdio>
int aux;

int gcd(int a, int b) { return (b == 0) ? a : gcd(b, a % b); }

int main() {
  int t;
  aux = scanf("%d", &t);
  while (t--) {
    int n;
    aux = scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) aux = scanf("%d", a + i);

    int acc = 0;

    for (int bit = 0; bit < 30; bit++) {
      int cnt = 0;
      for (int i = 0; i < n; i++) {
        if ((a[i] & (1 << bit)) != 0) cnt++;
      }
      acc = gcd(acc, cnt);
    }

    for (int i = 1; i <= n; i++)
      if (acc % i == 0) printf("%d ", i);

    puts("");
  }

  return 0;
}
