#include <algorithm>
#include <iostream>
using namespace std;

void update(int a[], int l, int r) {
  int i = l, j = r;
  while (i < j) {
    a[i] = a[j] = a[i] & a[j];
    i++;
    j--;
  }
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) scanf("%d", a + i);

    for (int l = 0; l < n; l++)
      for (int r = l + 1; r < n; r++) update(a, l, r);

    int ans = 0;
    for (int i = 0; i < n; i++) ans = max(ans, a[i]);
    printf("%d\n", ans);
  }

  return 0;
}
