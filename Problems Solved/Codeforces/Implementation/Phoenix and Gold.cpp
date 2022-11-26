#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, x;
    scanf("%d%d", &n, &x);
    vector<int> a(n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    int s = 0;
    for (int i = 0; i < n; i++) s += a[i];

    if (s == x)
      puts("NO");
    else {
      puts("YES");
      s = 0;

      for (int i = 0; i < n; i++) {
        if (s + a[i] == x) swap(a[i], a[i + 1]);
        printf("%d ", a[i]);
        s += a[i];
      }

      puts("");
    }
  }

  return 0;
}
