#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long u64;
typedef __uint128_t u128;

u64 mult(u64 a, u64 b, u64 m) {
  a %= m;
  b %= m;
  return ((u128)a * b) % m;
}

u64 binpow(u64 a, u64 b, u64 m) {
  u64 ret = 1;
  while (b) {
    if (b & 1) ret = mult(ret, a, m);
    a = mult(a, a, m);
    b >>= 1;
  }
  return ret;
}

bool check_composite(u64 a, u64 n, u64 d, int s) {
  u64 x = binpow(a, d, n);
  if (x == 1 || x == n - 1) return false;
  for (int i = 0; i < s; i++) {
    x = mult(x, x, n);
    if (x == n - 1) return false;
  }
  return true;
}

u64 f(u64 x, u64 c, u64 m) { return (mult(x, x, m) + c) % m; }

bool rabin(u64 n) {
  int s = 0;
  u64 d = n - 1;
  while (!(d & 1)) {
    s++;
    d >>= 1;
  }
  for (u64 a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
    if (n == a) return true;
    if (check_composite(a, n, d, s)) return false;
  }
  return true;
}

u64 rho(u64 n) {
  if (!(n & 1)) return 2;
  u64 x = 2, y = 2, c = rand() % n + 1, g = 1;
  while (g == 1) {
    x = f(x, c, n);
    y = f(f(y, c, n), c, n);
    u64 r = (x > y) ? x - y : y - x;
    g = __gcd(r, n);
  }
  return g;
}

void fact(u64 n, map<u64, u64>& mp) {
  if (n <= 1) return;

  if (rabin(n))
    mp[n]++;
  else {
    u64 r = rho(n);
    fact(r, mp);
    fact(n / r, mp);
  }
}

const int MAXN = 2000;

int n, m;
u64 a[MAXN], b[MAXN];

u64 bs(u64 g, u64 p, u64 k) {
  u64 l = 0, r = k;
  while (r > l) {
    u64 mid = l + (r - l) / 2;

    bool can = true;
    u64 v = g;
    for (u64 i = 0; i < k - mid; i++) v /= p;
    for (int i = 0; i < n; i++) can &= (v % a[i] == 0);

    if (can)
      r = mid;
    else
      l = mid + 1;
  }
  return r;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < m; i++) cin >> b[i];

  u64 g = 0;
  for (int i = 0; i < m; i++) g = __gcd(b[i], g);

  bool can = true;
  for (int i = 0; i < n; i++) can &= (g % a[i] == 0);

  if (!can)
    cout << "0\n";
  else {
    map<u64, u64> mp;
    fact(g, mp);
    u64 ans = 1;

    for (auto [p, k] : mp) {
      ans *= (k - bs(g, p, k) + 1);
    }

    cout << ans << "\n";
  }

  return 0;
}
