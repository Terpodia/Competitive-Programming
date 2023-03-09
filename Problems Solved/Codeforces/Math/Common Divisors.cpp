#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n;
  cin >> n;
  ll a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  ll g = 0;
  for (int i = 0; i < n; i++) g = __gcd(g, a[i]);
  int ans = 0;
  for (ll i = 1; i * i <= g; i++) {
    if (g % i == 0) {
      if (i == g / i)
        ans++;
      else
        ans += 2;
    }
  }
  cout << ans << "\n";
  return 0;
}
