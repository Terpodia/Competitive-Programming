#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

typedef long long ll;

void fastIO() { cin.tie(0)->sync_with_stdio(0); }

ll calc(ll x) {
  ll ans = 0;
  while (x > 1) {
    ans++;
    x /= 4;
  }

  return ans;
}

int main() {
  fastIO();
  int m;
  cin >> m;
  ll n = calc(m) + 1;
  ll a[m];

  for (int i = 0; i < m; i++) cin >> a[i];
  sort(a, a + m, greater<ll>());

  ll ans = a[0] * n;
  ll pot = 1;

  for (int i = 1; i < m; i++) {
    if (i == pot) {
      n--;
      if ((double)pot * 4 < 1e9) pot *= 4;
    }

    ans += a[i] * n;
  }

  cout << ans << "\n";

  return 0;
}
