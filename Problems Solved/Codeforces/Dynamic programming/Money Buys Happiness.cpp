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

void solve() {
  int m;
  ll x;
  cin >> m >> x;
  ll c[m];
  int h[m], maxh = 0;
  forn(i, m) {
    cin >> c[i] >> h[i];
    maxh += h[i];
  }
  ll dp[m + 1][maxh + 1];
  forn(i, m + 1) forn(j, maxh + 1) dp[i][j] = INF;
  dp[0][0] = 0;

  fore(i, 1, m + 1) {
    fore(j, 0, maxh + 1) {
      dp[i][j] = dp[i - 1][j];
      if (j >= h[i - 1] &&
          dp[i - 1][j - h[i - 1]] + c[i - 1] <= x * (ll)(i - 1))
        dp[i][j] = min(dp[i][j], dp[i - 1][j - h[i - 1]] + c[i - 1]);
    }
  }
  dfor(i, maxh + 1) {
    if (dp[m][i] <= x * (ll)m) {
      cout << i << "\n";
      return;
    }
  }
  cout << "0\n";
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
