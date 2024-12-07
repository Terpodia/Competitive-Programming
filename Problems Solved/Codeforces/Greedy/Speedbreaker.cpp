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

  vector<int> l(n + 1, n + 1), r(n + 1, -1);

  forn(i, n) {
    l[a[i]] = min(l[a[i]], i);
    r[a[i]] = max(r[a[i]], i);
  }

  vector<pair<int, int>> c;

  fore(i, 2, n + 1) {
    l[i] = min(l[i], l[i - 1]);
    r[i] = max(r[i], r[i - 1]);
  }

  fore(i, 1, n + 1) if (l[i] != n + 1) {
    if (r[i] - l[i] + 1 > i) {
      cout << "0\n";
      return;
    }
    c.pb(make_pair(max(0, r[i] - i + 1), min(n - 1, i + l[i] - 1)));
  }
  sort(all(c));
  int rx = c[0].snd;
  fore(i, 1, len(c)) {
    if (c[i].fst > rx) {
      cout << "0\n";
      return;
    }
    rx = min(rx, c[i].snd);
  }
  cout << rx - c.back().fst + 1 << "\n";
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
