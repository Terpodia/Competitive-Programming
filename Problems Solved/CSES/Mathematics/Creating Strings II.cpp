#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

const int MAXN = 1e6 + 10;
const ll MOD = 1e9 + 7;

ll f[MAXN];

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
  f[0] = 1;
  for (int i = 1; i < MAXN; i++) f[i] = (f[i - 1] * (ll)i) % MOD;
  char s[MAXN];
  scanf("%s", s);
  int n = strlen(s);
  vector<ll> cnt(26, 0);
  for (int i = 0; i < n; i++) cnt[s[i] - 'a']++;

  ll ans = f[n];
  for (int i = 0; i < 26; i++) {
    if (cnt[i] > 0) ans = (ans * inv(f[cnt[i]])) % MOD;
  }
  printf("%lld\n", ans);
  return 0;
}
