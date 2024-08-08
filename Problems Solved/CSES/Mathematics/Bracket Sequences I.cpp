#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;
const int MAXN = 1e6 + 10;

ll binpow(ll a, ll b) {
  ll ret = 1;
  while (b) {
    if (b & 1) ret = (ret * a) % MOD;
    a = (a * a) % MOD;
    b >>= 1;
  }
  return ret;
}
ll inv(ll a) { return binpow(a, MOD - 2); }

int main() {
  ll cat[MAXN];
  cat[0] = 1;
  for (int i = 0; i < MAXN - 1; i++) {
    cat[i + 1] = (cat[i] * (ll)(4 * i + 2));
    cat[i + 1] %= MOD;
    cat[i + 1] *= inv(i + 2);
    cat[i + 1] %= MOD;
  }
  int n;
  scanf("%d", &n);
  if (n % 2 == 1)
    printf("0\n");
  else
    printf("%lld\n", cat[n / 2]);
  return 0;
}
