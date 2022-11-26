#include <cstdio>
int aux;

typedef long long ll;

int main() {
  int tc;
  aux = scanf("%d", &tc);
  while (tc--) {
    int n, m;
    aux = scanf("%d%d", &n, &m);
    ll a[n], b[m];

    for (int i = 0; i < n; i++) aux = scanf("%lld", a + i);
    for (int i = 0; i < m; i++) aux = scanf("%lld", b + i);

    ll s1 = 0, s2 = 0;

    int ans = 0;

    for (int i = 0; i < n; i++) s1 += a[i];
    for (int i = 0; i < m; i++) s2 += b[i];

    for (int i = 0; i < n; i++) {
      if ((s1 - a[i]) * n > s1 * (n - 1)) {
        if (m == 0)
          ans++;
        else if ((s2 + a[i]) * m > s2 * (m + 1))
          ans++;
      }
    }

    printf("%d\n", ans);
  }

  return 0;
}
