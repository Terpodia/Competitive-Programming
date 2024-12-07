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
  ll a[n];
  forn(i, n) cin >> a[i];
  vector<pair<ll, ll>> v;
  forn(i, n) {
    ll sum = a[i], cnt = 1;
    while (!v.empty() && v.back().fst > sum / cnt) {
      sum += v.back().fst * v.back().snd, cnt += v.back().snd;
      v.pop_back();
    }
    v.pb(make_pair(sum / cnt, cnt - (sum % cnt)));
    if (sum % cnt > 0) v.pb(make_pair((sum + cnt - 1) / cnt, sum % cnt));
  }
  ll ans = v.back().fst - v[0].fst;
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) solve();
  return 0;
}
