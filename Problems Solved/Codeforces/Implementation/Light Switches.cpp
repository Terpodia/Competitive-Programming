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
  int n, k;
  cin >> n >> k;
  ll a[n];
  forn(i, n) cin >> a[i];
  sort(a, a + n);
  vector<pair<int, int>> p;

  forn(i, n - 1) {
    // a[i] + 2b * k >= a[n-1]
    // b >= (a[n-1] - a[i]) / 2k
    int b = (a[n - 1] - a[i] + 2 * k - 1) / (2 * k);
    int c = (a[n - 1] - a[i]) / (2 * k);
    if (a[i] + 2 * b * k >= a[n - 1] && a[i] + 2 * b * k < a[n - 1] + k) {
      p.pb(make_pair(a[i] + 2 * b * k, a[i] + 2 * b * k + k - 1));
    } else {
      p.pb(make_pair(a[i] + 2 * c * k, a[i] + 2 * c * k + k - 1));
    }
  }
  p.push_back(make_pair(a[n - 1], a[n - 1] + k - 1));
  sort(all(p));
  int l = -1, r = INF;
  for (auto [x, y] : p) {
    l = max(l, x);
    r = min(r, y);
  }
  if (r < l)
    cout << "-1\n";
  else
    cout << l << "\n";
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
