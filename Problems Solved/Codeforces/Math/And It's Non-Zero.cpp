#include <algorithm>
#include <cstdio>
using namespace std;
int aux;

const int INF = 1e9;

int f(int b, int k) {
  int d = (k + 1) / (1 << (b + 1));
  int r = (k + 1) % (1 << (b + 1));

  int ret = d * (1 << b);

  ret += max(0, r - (1 << b));

  return ret;
}

int main() {
  int tc;
  aux = scanf("%d", &tc);
  while (tc--) {
    int l, r;
    aux = scanf("%d%d", &l, &r);
    int ans = INF;
    for (int i = 0; i < 30; i++) {
      ans = min(ans, r - l + 1 - f(i, r) + f(i, l - 1));
    }
    printf("%d\n", ans);
  }

  return 0;
}
