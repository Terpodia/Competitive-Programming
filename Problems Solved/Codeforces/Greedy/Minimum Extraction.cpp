#include <algorithm>
#include <iostream>
using namespace std;
int aux;

typedef long long ll;

const ll INF = 1e18;

int main() {
  int t;
  aux = scanf("%d", &t);
  while (t--) {
    int n;
    aux = scanf("%d", &n);
    ll a[n];
    for (int i = 0; i < n; i++) aux = scanf("%lld", a + i);
    sort(a, a + n);

    ll acc = 0, ans = -INF;
    for (int i = 0; i < n; i++) {
      ans = max(ans, a[i] + acc);
      acc -= (a[i] + acc);
    }

    printf("%lld\n", ans);
  }

  return 0;
}
