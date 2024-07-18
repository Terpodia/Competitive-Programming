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

void solve() {
  int n;
  cin >> n;
  int a[n];
  forn(i, n) cin >> a[i];

  ll ans = 0;
  fore(i, 1, n) { ans += ((ll)i * (ll)(i + 1)) / 2LL; }
  forn(i, n - 1) {
    int pref[n + 1];
    pref[i + 1] = a[i + 1];
    fore(j, i + 2, n) pref[j] = min(pref[j - 1], a[j]);
    int r = n - 1;
    int cur = a[i];

    dfor(j, i + 1) {
      cur = max(cur, a[j]);
      while (cur > pref[r] && r > i) r--;
      ans -= (ll)r - (ll)i;
    }
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
