#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll R, D;

// x^2 + y^2 <= R^2

bool f(ll x, ll y, ll r) {
  return x * x + y * y <= (R - r) * (R - r) &&
         x * x + y * y >= (R - D + r) * (R - D + r);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> R >> D;
  int n, ans = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    ll x, y, r;
    cin >> x >> y >> r;
    bool can = true;
    can &= f(x, y, r);
    if (can) {
      ans++;
    }
  }
  cout << ans << "\n";
  return 0;
}
