#include <algorithm>
#include <cstdio>
using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);

    int x = n / k;
    int mx = min(x, m), r = 0;

    m -= mx, k--;

    while (m > 0) {
      m -= k;
      r++;
    }

    printf("%d\n", mx - r);
  }

  return 0;
}
