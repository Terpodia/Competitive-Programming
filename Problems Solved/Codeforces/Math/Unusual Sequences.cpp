#pragma GCC optimize("O3,unroll-loops")

#include "bits/stdc++.h"
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

const int INF = 1e9;

const ll MOD = 1e9 + 7;

vector<ll> d;

ll binpow(ll a, ll b) {
  ll ret = 1;
  while (b) {
    if (b & 1) ret = (ret * a) % MOD;
    a = (a * a) % MOD;
    b >>= 1;
  }
  return ret;
}

unordered_map<ll, ll> dp;

ll solve(ll y) {
  if (dp.find(y) != dp.end()) return dp[y];
  ll res = binpow(2, y - 1);
  forn(i, len(d)) if (y % d[i] == 0) {
    res = (res - solve(y / d[i])) % MOD;
    res += MOD, res %= MOD;
  }
  return dp[y] = res;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ll x, y;
  cin >> x >> y;
  if (y % x != 0) {
    cout << "0\n";
    return 0;
  }
  y /= x;
  if (y != 1) d.pb(y);
  for (ll i = 2; i * i <= y; i++)
    if (y % i == 0) {
      d.pb(i);
      if (y / i != i) d.pb(y / i);
    }
  cout << solve(y) << "\n";
  return 0;
}
