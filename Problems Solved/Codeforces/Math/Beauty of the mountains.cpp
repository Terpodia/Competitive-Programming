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
  int n, m, k;
  cin >> n >> m >> k;
  ll a[n][m];
  string b[n];
  forn(i, n) forn(j, m) cin >> a[i][j];
  forn(i, n) cin >> b[i];
  ll pref[2][n + 1][m + 1];
  ll sum = 0;
  memset(pref, 0, sizeof(pref));
  fore(i, 1, n + 1) fore(j, 1, m + 1) {
    pref[0][i][j] =
        pref[0][i - 1][j] + pref[0][i][j - 1] - pref[0][i - 1][j - 1];
    pref[1][i][j] =
        pref[1][i - 1][j] + pref[1][i][j - 1] - pref[1][i - 1][j - 1];
    pref[b[i - 1][j - 1] - '0'][i][j]++;

    if (b[i - 1][j - 1] == '0')
      sum += a[i - 1][j - 1];
    else
      sum -= a[i - 1][j - 1];
  }
  ll g = 0;

  forn(i, n - k + 1) forn(j, m - k + 1) {
    int r1 = i + 1, c1 = j + 1, r2 = i + k, c2 = j + k;
    ll c = pref[0][r2][c2] - pref[0][r1 - 1][c2] - pref[0][r2][c1 - 1] +
           pref[0][r1 - 1][c1 - 1];
    ll d = pref[1][r2][c2] - pref[1][r1 - 1][c2] - pref[1][r2][c1 - 1] +
           pref[1][r1 - 1][c1 - 1];
    g = __gcd(g, abs(c - d));
  }
  if (g != 0 && abs(sum) % g == 0)
    cout << "YES\n";
  else if (sum == 0)
    cout << "YES\n";
  else
    cout << "NO\n";
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
