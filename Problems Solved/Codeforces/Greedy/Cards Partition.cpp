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
  ll k;
  cin >> n >> k;
  ll a[n];
  forn(i, n) cin >> a[i];
  sort(a, a + n);
  ll s = 0;
  forn(i, n) s += a[i];

  int ans = 1;

  for (ll j = 2; j <= n; j++) {
    ll r = s % j;
    ll ss = s + ((r > 0) ? (j - r) : 0);
    ll q = k - ((r > 0) ? (j - r) : 0);

    if (q < 0) continue;

    ss += (q / j) * j;

    if (ss / j >= a[n - 1]) ans = j;
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
