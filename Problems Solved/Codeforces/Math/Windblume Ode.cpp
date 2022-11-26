#include <iostream>
using namespace std;

int aux;

bool isPrime(int p) {
  for (int i = 2; i * i <= p; i++)
    if (p % i == 0) return false;

  return true;
}

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

    if (!isPrime(s)) {
      printf("%d\n", n);
      for (int i = 1; i <= n; i++) printf("%d%c", i, " \n"[i == n]);
    } else {
      int j = -1;
      for (int i = 0; i < n; i++)
        if (!isPrime(s - a[i])) j = i;

      printf("%d\n", n - 1);
      for (int i = 0; i < n; i++)
        if (j != i) {
          printf("%d ", i + 1);
        }
      puts("");
    }
  }

  return 0;
}
