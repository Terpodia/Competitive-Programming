#include <algorithm>
#include <cstdio>
using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
  int t;
  scanf("%d", &t);

  while (t--) {
    int n;
    scanf("%d", &n);
    ll a[n];
    for (int i = 0; i < n; i++) scanf("%lld", a + i);

    sort(a, a + n);
    ll s1 = 0, s2 = a[n - 1];
    for (int i = 0; i < n - 1; i++) s1 += a[i];

    printf("%.12Lf\n", (ld)s1 / (n - 1) + (ld)s2);
  }

  return 0;
}
