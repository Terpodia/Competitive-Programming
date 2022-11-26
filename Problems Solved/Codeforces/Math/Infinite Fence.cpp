#include <algorithm>
#include <cstdio>
using namespace std;
int aux;

typedef long long ll;

int main() {
  int tc;
  aux = scanf("%d", &tc);
  while (tc--) {
    ll r, b, k;
    aux = scanf("%lld%lld%lld", &r, &b, &k);

    if (r > b) swap(r, b);

    ll g = __gcd(r, b);
    r /= g;
    b /= g;

    if (b <= (k - 1) * r + 1)
      puts("OBEY");
    else
      puts("REBEL");
  }

  return 0;
}
