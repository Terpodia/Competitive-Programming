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

const ll INF = 1e18;

ll f(ll u, ll k) {
  // dbg(u);
  // dbg(k);
  return u * k - (k * (k - 1LL)) / 2LL;
}

void solve() {
  int n;
  cin >> n;
  ll a[n];
  forn(i, n) cin >> a[i];

  ll pref[n + 1];
  pref[0] = 0;
  fore(i, 1, n + 1) pref[i] = pref[i - 1] + a[i - 1];
  int q;
  cin >> q;
  while (q--) {
    int lx;
    ll u;
    cin >> lx >> u;
    int l = lx, r = n;
    while (r > l) {
      int mid = l + (r - l + 1) / 2;
      if (pref[mid] - pref[lx - 1] <= u)
        l = mid;
      else
        r = mid - 1;
    }
    int ans = l;
    ll cnt = f(u, pref[l] - pref[lx - 1]);

    ll cnt2 = -INF;

    if (l < n) {
      cnt2 = f(u, pref[l + 1] - pref[lx - 1]);
    }
    // dbg(cnt);
    // dbg(cnt2);

    if (cnt2 > cnt) ans = l + 1;

    cout << ans << " ";
  }
  cout << "\n";
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
