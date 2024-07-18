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
  int n, m;
  cin >> n >> m;
  int a[n][m], b[n][m];
  forn(i, n) forn(j, m) {
    char c;
    cin >> c;
    a[i][j] = c - '0';
  }
  forn(i, n) forn(j, m) {
    char c;
    cin >> c;
    b[i][j] = c - '0';
  }

  forn(i, n - 1) forn(j, m - 1) {
    int r = i + 1, c = j + 1;
    int x = ((b[i][j] - a[i][j]) % 3 + 3) % 3;
    a[i][j] = (a[i][j] + x) % 3;
    a[r][c] = (a[r][c] + x) % 3;
    a[i][c] = (a[i][c] + 2 * x) % 3;
    a[r][j] = (a[r][j] + 2 * x) % 3;
  }

  forn(i, n) forn(j, m) {
    if (a[i][j] != b[i][j]) {
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
