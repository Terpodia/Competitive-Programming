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

void solve() {
  int n;
  ll x;
  cin >> n >> x;
  ll a[n];
  forn(i, n) cin >> a[i];
  ll pref[n + 1];
  pref[0] = 0;
  fore(i, 1, n + 1) pref[i] = pref[i - 1] + a[i - 1];

  int cur = n;
  ll ans = 0;

  ll dp[n + 1];
  forn(i, n + 1) dp[i] = 0;

  dfor(i, n) {
    if (pref[cur] - pref[i] > x) {
      int j = (int)(upper_bound(pref + i, pref + n + 1, x + pref[i]) - pref);
      dp[i] = 1 + dp[j];
      cur = --j;
    } else
      dp[i] = dp[i + 1];
    ans += (ll)n - (ll)i - dp[i];
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}
