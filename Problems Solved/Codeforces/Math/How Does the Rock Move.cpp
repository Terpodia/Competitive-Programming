#pragma GCC optimize("O3,unroll-loops")

#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <vector>
// #include<algorithm>
// #include <bits/stdc++.h>
using namespace std;

#define fst first
#define snd second
#define pb push_back
#define len(x) (int)x.size()
#define all(x) begin(x), end(x)
#define fore(i, a, b) for (auto i = a; i < b; i++)
#define forn(i, n) fore(i, 0, n)
#define dfor(i, n) for (auto i = n; i-- > 0;)
#define dbg(x) cerr << "LINE" $ __LINE__ << ":" $ #x << "=" << x << endl;
#define raya \
  cerr << "\n-----------------------------------------------------------\n"
#define $ << " " <<

template <typename T, typename U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
  os << '(' << p.first $ p.second << ')';
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  os << "[";
  forn(i, len(v)) {
    if (i) os << ", ";
    os << v[i];
  }
  os << "]";
  return os;
}

typedef long long ll;

const ll MOD = 1e9 + 7;
const int MAXN = 3e5 + 10;

ll binpow(ll a, ll b) {
  ll res = 1;
  while (b) {
    if (b & 1) res = (res * a) % MOD;
    b >>= 1LL;
    a = (a * a) % MOD;
  }
  return res;
}

ll inv(ll n) { return binpow(n, MOD - 2); }

ll f[MAXN], f2[MAXN];

ll comb(int n, int k) {
  ll num = f[n];
  ll den = (f[k] * f[n - k]) % MOD;
  return (num * inv(den)) % MOD;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  f[0] = 1;
  fore(i, 1, MAXN) f[i] = (f[i - 1] * (ll)i) % MOD;

  f2[0] = 1, f2[1] = 1;
  fore(i, 2, MAXN) f2[i] = (f2[i - 2] * (ll)i) % MOD;

  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    int m = n;
    forn(i, k) {
      int r, c;
      cin >> r >> c;
      if (r == c)
        m--;
      else
        m -= 2;
    }
    ll ans = 1;
    forn(i, m) {
      if ((m - i) % 2 != 0) continue;
      ans += ((comb(m, i) * f2[m - i - 1]) % MOD) * binpow(2, (m - i) / 2);
      ans %= MOD;
    }
    cout << ans << "\n";
  }
  return 0;
}
