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
  cin >> n;
  vector<ll> a(n);
  forn(i, n) cin >> a[i];
  ll ans = 0;

  forn(_, 2) {
    map<ll, int> m;
    m[0] = 0;
    ll cur = 0;
    forn(i, n) {
      ans += a[i];
      m[a[i]]++;
      if (m[a[i]] > 1 && a[i] > cur) {
        cur = a[i];
      }
      a[i] = cur;
    }
  }
  vector<ll> cnt(n + 1, 0);
  forn(i, n) cnt[a[i]]++;

  ll sum = 0;
  forn(i, n) sum += a[i];

  dfor(i, n + 1) {
    if (cnt[i] == 0) continue;
    sum -= cnt[i] * (ll)i;
    while (cnt[i] > 0) {
      ans += cnt[i] * (ll)i + sum;
      cnt[i]--;
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
