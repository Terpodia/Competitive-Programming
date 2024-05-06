#include <algorithm>
#include <cstdio>
using namespace std;

int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    if (k == 1)
      puts("1");
    else if (k > 3)
      puts("0");
    else {
      int cnt = m / n + min(n - 1, m);
      if (k == 2)
        printf("%d\n", cnt);
      else
        printf("%d\n", m - cnt);
    }
  }
  return 0;
}
