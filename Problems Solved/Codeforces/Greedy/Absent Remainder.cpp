#include <algorithm>
#include <cstdio>
using namespace std;
int aux;

int main() {
  int t;
  aux = scanf("%d", &t);

  while (t--) {
    int n;
    aux = scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) aux = scanf("%d", a + i);

    sort(a, a + n);

    int m = a[0];

    int cnt = 0;

    for (int i = 1; i < n; i++) {
      if (cnt == n / 2) break;
      printf("%d %d\n", a[i], m);
      cnt++;
    }
  }

  return 0;
}
