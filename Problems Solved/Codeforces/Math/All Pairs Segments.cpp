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
  int n, q;
  cin >> n >> q;
  ll x[n];
  forn(i, n) cin >> x[i];
  map<ll, ll> cnt;
  forn(i, n) {
    ll y = (ll)(i + 1) * (ll)(n - i) - 1LL;
    cnt[y]++;
  }
  forn(i, n - 1) {
    ll l = x[i], r = x[i + 1];
    ll y = (ll)i * (ll)(n - 1 - i) + (ll)(n - i - 1);
    cnt[y] += (ll)(r - 1) - (ll)(l + 1) + 1LL;
  }
  while (q--) {
    ll k;
    cin >> k;
    if (cnt.find(k) != cnt.end())
      cout << cnt[k] << " ";
    else
      cout << "0 ";
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
