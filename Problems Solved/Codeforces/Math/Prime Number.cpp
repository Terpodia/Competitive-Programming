#include <cstdio>
#include <map>
using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;

ll binpow(ll x, ll p) {
  ll ret = 1;
  while (p) {
    if (p & 1) ret = (ret * x) % MOD;
    x = (x * x) % MOD;
    p >>= 1;
  }
  return ret;
}

int main() {
  int n;
  ll x;
  scanf("%d%lld", &n, &x);
  ll a[n];
  for (int i = 0; i < n; i++) scanf("%lld", a + i);

  ll s = 0;
  for (int i = 0; i < n; i++) s += a[i];
  for (int i = 0; i < n; i++) a[i] = s - a[i];

  map<ll, ll> mp;
  for (int i = 0; i < n; i++) mp[a[i]]++;

  ll p = 0, r = 0;

  while (!mp.empty()) {
    auto it = mp.begin();
    p += it->first - r;

    if (it->second % x != 0) break;

    ll cnt = it->second / x;
    mp[it->first + 1] += cnt;
    r += it->first - r;
    mp.erase(mp.begin());
  }

  printf("%lld\n", binpow(x, min(s, p)));

  return 0;
}

