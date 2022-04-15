#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    pair<int, int> a[n];
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i].first);
      a[i].second = i;
    }
    sort(a, a + n);
    printf("%d %d\n", a[0].second + 1, a[n - 1].second + 1);
  }
  return 0;
}

