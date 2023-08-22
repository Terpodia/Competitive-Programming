#include <iostream>
#include <map>
using namespace std;
using ll = long long;

const int MAXN = 2e5;
int n;
ll x;
ll a[MAXN];

ll solve() {
  ll ans = 0;
  map<ll, ll> mp;

  ll psum = 0;

  for (int i = 0; i < n; i++) {
    psum += a[i];
    if (mp.find(psum - x) != mp.end()) ans += mp[psum - x];
    if (psum == x) ans++;

    mp[psum]++;
  }

  return ans;
}

int main() {
  scanf("%d%lld", &n, &x);
  for (int i = 0; i < n; i++) scanf("%lld", a + i);

  printf("%lld\n", solve());

  return 0;
}
