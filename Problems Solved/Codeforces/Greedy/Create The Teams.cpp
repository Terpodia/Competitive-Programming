#include <algorithm>
#include <iostream>
using namespace std;

typedef long long ll;

const ll INF = 1e18;

int main() {
  int t;
  scanf("%d", &t);

  while (t--) {
    int n;
    ll x;
    scanf("%d%lld", &n, &x);
    ll a[n];
    for (int i = 0; i < n; i++) scanf("%lld", a + i);

    sort(a, a + n, greater<ll>());

    ll curr = INF, cnt = 0;

    int ans = 0;

    for (int i = 0; i < n; i++) {
      curr = min(curr, a[i]);
      cnt++;
      if (cnt * curr >= x) ans++, curr = INF, cnt = 0;
    }

    printf("%d\n", ans);
  }

  return 0;
}
