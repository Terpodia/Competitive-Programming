#include <algorithm>
#include <cstdio>
using namespace std;

typedef long long ll;

const int INF = 1e9;

ll a, b;

ll lastOne(ll x) {
  for (ll i = 60; i >= 0; i--)
    if (x & (1LL << i)) {
      return i;
    }
  return 0;
}

bool isSuffix(ll x, ll y) {
  ll n = lastOne(x), m = lastOne(y);
  if (n < m) return false;
  ll i = n, j = m;
  while (j > -1) {
    bool bit1 = x & (1LL << i), bit2 = y & (1LL << j);
    if (bit1 != bit2) return false;
    i--, j--;
  }
  return true;
}

void solve() {
  int ans = INF;
  for (int d = 0; d <= 70; d++)
    for (int s = 0; s <= 70; s++) {
      ll c = a;
      int acc = 0;
      for (int i = 0; i < d; i++) {
        if (c % 2 != 0) c++, acc++;
        c /= 2;
        acc++;
      }
      for (int i = 0; i < s; i++) acc++, c++;

      if (!isSuffix(b, c)) continue;

      for (ll i = lastOne(b) - lastOne(c) - 1; i >= 0; i--)
        acc += (b & (1LL << i)) ? 2 : 1;

      ans = min(acc, ans);
    }

  printf("%d\n", ans);
}

int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    scanf("%lld%lld", &a, &b);
    solve();
  }
  return 0;
}
