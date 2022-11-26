#include <iostream>
using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;

ll binpow(ll a, ll b) {
  ll ret = 1;
  while (b > 0) {
    if (b & 1) ret = (ret * a) % MOD;
    b >>= 1;
    a = (a * a) % MOD;
  }
  return ret;
}

int main(void) {
  int n;
  scanf("%d", &n);
  while (n--) {
    ll a, b;
    scanf("%lld%lld", &a, &b);
    printf("%lld\n", binpow(a, b));
  }

  return 0;
}
