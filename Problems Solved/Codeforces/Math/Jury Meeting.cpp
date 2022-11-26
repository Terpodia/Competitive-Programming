#include <algorithm>
#include <iostream>
using namespace std;

typedef long long ll;

const ll MOD = 998244353;
const int MAXN = 2e5 + 7;

ll binpow(ll a, ll b) {
  ll ret = 1;
  while (b) {
    if (b & 1) ret = (ret * a) % MOD;
    a = (a * a) % MOD;
    b >>= 1;
  }

  return ret;
}

ll f(ll a[], int n) {
  ll cnt = 0;
  for (int i = 1; i < n; i++) {
    if (a[0] - a[i] > 1) break;
    cnt++;
  }
  return cnt;
}

int main() {
  int t;
  scanf("%d", &t);

  ll fact[MAXN];

  fact[0] = 1;
  for (ll i = 1; i < MAXN; i++) fact[i] = (fact[i - 1] * i) % MOD;

  while (t--) {
    int n;
    scanf("%d", &n);
    ll a[n];
    for (int i = 0; i < n; i++) scanf("%lld", a + i);

    sort(a, a + n, greater<ll>());

    if (a[0] == a[1])
      printf("%lld\n", fact[n]);

    else if (a[0] - a[1] > 1)
      puts("0");

    else {
      ll cnt = f(a, n);
      ll ans = 0, acc = fact[cnt], curr = 1;

      for (ll i = cnt; i < n; i++) {
        ans = (ans + ((acc * fact[n - cnt - 1])) % MOD) % MOD;
        acc = (acc * binpow(curr++, MOD - 2)) % MOD;
        acc = (acc * (i + 1)) % MOD;
      }

      ans = (fact[n] - ans + MOD) % MOD;

      printf("%lld\n", ans);
    }
  }

  return 0;
}
