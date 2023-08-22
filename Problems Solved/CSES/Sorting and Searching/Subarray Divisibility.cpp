#include <iostream>
#include <map>
using namespace std;
using ll = long long;

const int MAXN = 2e5;
int n;
ll a[MAXN];

ll solve() {
  ll ret = 0, psum = 0;
  map<ll, ll> mp;

  for (int i = 0; i < n; i++) {
    psum += a[i];
    ll mod = ((psum % (ll)n) + (ll)n) % (ll)n;

    if (mp.find(mod) != mp.end()) ret += mp[mod];
    if (mod == 0) ret++;
    mp[mod]++;
  }

  return ret;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%lld", a + i);
  printf("%lld\n", solve());

  return 0;
}
