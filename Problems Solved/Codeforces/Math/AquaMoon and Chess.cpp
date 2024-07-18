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

const ll MOD = 998244353;

const int MAXN = 1e5 + 10;

ll fact[MAXN];

ll binpow(ll a, ll b) {
  ll ret = 1;
  while (b) {
    if (b & 1) ret = (ret * a) % MOD;
    a = (a * a) % MOD;
    b >>= 1;
  }
  return ret;
}

ll comb(int n, int k) {
  ll num = fact[n];
  ll den = (fact[k] * fact[n - k]) % MOD;
  return (num * binpow(den, MOD - 2)) % MOD;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  fact[0] = 1;
  fore(i, 1, MAXN) fact[i] = (fact[i - 1] * (ll)i) % MOD;

  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt0 = 0, cnt1 = 0;
    forn(i, len(s) - 1) {
      if (s[i] == '0') cnt0++;
      if (s[i] == '1' && s[i + 1] == '1') cnt1++, i++;
    }
    if (s[len(s) - 1] == '0') cnt0++;
    // dbg(cnt0);
    // dbg(cnt1);
    cout << comb(cnt0 + cnt1, cnt1) << "\n";
  }
  return 0;
}
