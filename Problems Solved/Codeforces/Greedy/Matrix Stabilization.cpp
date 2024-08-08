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

const int rm[] = {1, -1, 0, 0}, cm[] = {0, 0, 1, -1};

const int INF = 1e9 + 100;

void solve() {
  int n, m;
  cin >> n >> m;
  int a[n][m];
  forn(i, n) forn(j, m) cin >> a[i][j];
  forn(i, n) forn(j, m) {
    int hi = -INF;
    for (int _ = 0; _ < 4; _++) {
      int r = i + rm[_];
      int c = j + cm[_];
      if (r >= 0 && c >= 0 && r < n && c < m) hi = max(hi, a[r][c]);
    }
    if (hi < a[i][j]) a[i][j] = hi;
  }

  forn(i, n) {
    forn(j, m) cout << a[i][j] << " ";
    cout << "\n";
  }
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
