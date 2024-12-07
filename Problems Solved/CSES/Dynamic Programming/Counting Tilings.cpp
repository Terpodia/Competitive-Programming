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

const int MOD = 1e9 + 7;

const int INF = 1e9;

int n, m, dp[11][1001][1 << 10];

int solve(int r, int c, int msk) {
  int &ret = dp[r][c][msk];
  if (ret != -1) return ret;
  ret = 0;
  if (c == m - 1) {
    bool ok = true;
    forn(i, n) {
      if (msk & (1 << i)) continue;
      if (i == n - 1 || msk & (1 << (i + 1))) ok = false;
      msk |= (1 << i);
      msk |= (1 << (i + 1));
    }
    if (ok) ret = 1;
    return ret;
  }
  if (r == n) {
    int nmsk = 0;
    forn(i, n) {
      if (msk & (1 << i)) continue;
      nmsk |= (1 << i);
    }
    return ret = solve(0, c + 1, nmsk);
  }
  ret = solve(r + 1, c, msk);
  if (r < n - 1 && !(msk & (1 << r)) && !(msk & (1 << (r + 1)))) {
    int nmsk = msk;
    nmsk |= (1 << r);
    nmsk |= (1 << (r + 1));
    ret += solve(r + 2, c, nmsk);
    ret %= MOD;
  }
  return ret;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  memset(dp, -1, sizeof(dp));
  cout << solve(0, 0, 0) << "\n";
  return 0;
}
