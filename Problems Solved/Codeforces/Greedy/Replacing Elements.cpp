#include <stdio.h>

#include <algorithm>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, d;
    scanf("%d%d", &n, &d);
    int a[n];
    for (int i = 0; i < n; i++) scanf("%d", a + i);

    sort(a, a + n);
    bool flag = true;

    for (int i = 0; i < n; i++) {
      if (a[i] > d && a[0] + a[1] > d) {
        flag = false;
      }
    }

    if (flag)
      printf("YES\n");
    else
      printf("NO\n");
  }

  return 0;
}
