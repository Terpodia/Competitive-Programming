#include <iostream>
using namespace std;
int aux;

typedef long long ll;

int main() {
  int t;
  aux = scanf("%d", &t);
  while (t--) {
    ll x0, n;
    aux = scanf("%lld%lld", &x0, &n);

    ll i = n % 4;
    ll ans = x0;

    while (i > 0) {
      if (abs(ans) % 2 == 0)
        ans -= n - i + 1;
      else
        ans += n - i + 1;
      i--;
    }

    printf("%lld\n", ans);
  }

  return 0;
}
