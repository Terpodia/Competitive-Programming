#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
int aux;

const int INF = 1e9;

int main() {
  int t;
  aux = scanf("%d", &t);

  while (t--) {
    int n, a, b;
    aux = scanf("%d%d%d", &n, &a, &b);
    int p[n];
    bool ok[n * 10];
    memset(ok, false, sizeof(ok));

    for (int i = 0; i < n; i++) p[i] = INF;

    p[0] = a;
    p[n / 2] = b;
    ok[a] = true;
    ok[b] = true;

    for (int i = 1; i < n / 2; i++) {
      for (int j = n; j > 0; j--)
        if (!ok[j]) {
          p[i] = j, ok[j] = true;
          break;
        }
    }

    for (int i = (n / 2) + 1; i < n; i++) {
      for (int j = 1; j <= n; j++)
        if (!ok[j]) {
          p[i] = j, ok[j] = true;
          break;
        }
    }

    bool can = true;

    int lo = INF, hi = -INF;

    for (int i = 0; i < n; i++) {
      if (p[i] > n || p[i] < 1) can = false;
      if (i < n / 2)
        lo = min(p[i], lo);
      else
        hi = max(p[i], hi);
    }

    can &= (lo == a && hi == b);

    if (can) {
      for (int i = 0; i < n; i++) printf("%d%c", p[i], " \n"[i == n - 1]);
    } else
      puts("-1");
  }

  return 0;
}
