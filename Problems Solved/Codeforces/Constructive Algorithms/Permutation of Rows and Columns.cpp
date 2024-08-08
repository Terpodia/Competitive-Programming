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
typedef vector<int> vi;
typedef vector<vi> vvi;

void solve() {
  int n, m;
  cin >> n >> m;
  vvi a(n, vi(m)), b(n, vi(m));
  forn(i, n) forn(j, m) cin >> a[i][j];
  forn(i, n) forn(j, m) cin >> b[i][j];

  vector<int> p;

  forn(i, n) {
    if (!p.empty()) break;
    vi c(n * m + 1, -1);
    forn(j, m) c[b[i][j]] = j;
    bool flag = true;
    forn(j, m) if (c[a[0][j]] == -1) flag = false;

    if (!flag) continue;
    p = vi(m, -1);
    forn(j, m) p[j] = c[a[0][j]];
  }
  if (p.empty()) {
    cout << "NO\n";
    return;
  }
  set<vi> s;
  forn(i, n) {
    vi v(m, -1);
    forn(j, m) v[p[j]] = a[i][j];
    s.insert(v);
  }
  forn(i, n) {
    if (s.find(b[i]) == s.end()) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
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
