#include <bits/stdc++.h>
using namespace std;

#define SZ(x) (int)x.size()

typedef long long ll;

int main() {
  int n;
  cin >> n;
  ll a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  vector<ll> p[64];
  for (int i = 0; i < n; i++) p[__builtin_clzll(a[i])].push_back(a[i]);
  for (int i = 0; i < 64; i++) {
    while (SZ(p[i]) > 1) {
      ll x = (p[i][0] ^ p[i].back());
      if (x > 0) p[__builtin_clzll(x)].push_back(x);
      p[i].pop_back();
    }
  }
  ll x = 0;
  for (int i = 0; i < 64; i++) {
    if (!SZ(p[i])) continue;
    ll nx = (x ^ p[i][0]);
    if (nx > x) x = nx;
  }
  cout << x << "\n";
  return 0;
}
