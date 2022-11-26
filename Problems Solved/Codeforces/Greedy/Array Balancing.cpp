#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;

typedef long long ll;

int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    ll a[n], b[n];
    for (int i = 0; i < n; i++) scanf("%lld", a + i);
    for (int i = 0; i < n; i++) scanf("%lld", b + i);
    ll ans = 0;
    for (int i = 0; i < n - 1; i++) {
      ans += min(abs(a[i] - a[i + 1]) + abs(b[i] - b[i + 1]),
                 abs(b[i] - a[i + 1]) + abs(a[i] - b[i + 1]));
    }
    printf("%lld\n", ans);
  }
  return 0;
}
