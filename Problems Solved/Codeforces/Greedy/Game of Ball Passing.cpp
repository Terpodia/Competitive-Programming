#include <algorithm>
#include <cstdio>
using namespace std;

typedef long long ll;

const ll INF = 1e18;

int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    ll a[n];
    for (int i = 0; i < n; i++) scanf("%lld", a + i);
    ll sum = 0, hi = -INF;
    for (int i = 0; i < n; i++) sum += a[i], hi = max(hi, a[i]);
    if (hi == 0)
      puts("0");
    else if (hi <= sum - hi)
      puts("1");
    else
      printf("%lld\n", hi * 2 - sum);
  }
  return 0;
}

