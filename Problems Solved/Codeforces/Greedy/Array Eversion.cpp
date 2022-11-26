#include <algorithm>
#include <iostream>
using namespace std;
int aux;

const int INF = 1e9;

int main() {
  int TC;
  aux = scanf("%d", &TC);
  while (TC--) {
    int n;
    aux = scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) aux = scanf("%d", a + i);

    int hi = -INF;

    for (int i = 0; i < n; i++) hi = max(hi, a[i]);

    int ans = 0, i = n - 1;

    while (a[i] != hi) {
      ans++;
      int j = i - 1;
      while (j > -1 && a[j] <= a[i]) j--;
      i = j;
    }

    printf("%d\n", ans);
  }

  return 0;
}
