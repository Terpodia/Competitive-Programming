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

const ll MOD = 998244353;
const int MAXN = 2e5 + 10;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ll po[MAXN];
  po[0] = 1;
  fore(i, 1, MAXN) po[i] = (po[i - 1] * 2LL) % MOD;
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    ll a[n];
    forn(i, n) cin >> a[i];

    ll pref[n + 1];
    pref[0] = 0;
    fore(i, 1, n + 1) pref[i] = pref[i - 1] + a[i - 1];

    bool flag = true;
    fore(i, 1, n + 1) flag &= pref[i] >= 0;

    if (flag) {
      cout << po[n] << "\n";
      continue;
    }

    ll hi = 0;
    fore(i, 1, n + 1) {
      hi = max(hi, abs(pref[i - 1] + a[i - 1]) + pref[n] - pref[i]);
    }
    ll c = 0;

    ll p[n + 1];
    p[0] = 1;

    fore(i, 0, n) {
      p[i + 1] = p[i];
      c += a[i];
      if (c >= 0) p[i + 1] = (p[i + 1] * 2LL) % MOD;
    }
    ll ans = 0;
    fore(i, 1, n + 1) {
      ll s = abs(pref[i - 1] + a[i - 1]) + pref[n] - pref[i];
      if (s == hi) {
        ans += p[i] * po[n - i];
        ans %= MOD;
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
