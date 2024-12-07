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

string c;

ll dp[20][11][2][2];

ll solve(int i, int ls, int flag, int zero) {
  ll &ret = dp[i][ls][flag][zero];
  if (ret != -1) return ret;
  if (i == len(c)) return ret = 1;
  ret = 0;
  if (i == 0) {
    ret += solve(i + 1, 0, 1, 0);
    fore(j, 1, c[0] - '0') ret += solve(i + 1, j, 1, 1);
    if (c[0] != '0') ret += solve(i + 1, c[0] - '0', 0, 1);
  } else {
    if (flag == 0) {
      forn(j, c[i] - '0') {
        if (j != ls) ret += solve(i + 1, j, 1, zero);
      }
      if (c[i] - '0' != ls) ret += solve(i + 1, c[i] - '0', 0, zero);
    } else {
      if (zero == 0)
        ret += solve(i + 1, 0, 1, 0);
      else if (ls != 0)
        ret += solve(i + 1, 0, 1, 1);
      fore(j, 1, 10) {
        if (j != ls) ret += solve(i + 1, j, 1, 1);
      }
    }
  }
  return ret;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ll a, b;
  cin >> a >> b;
  ll ans = 0;
  c = to_string(b);
  memset(dp, -1, sizeof(dp));
  ans += solve(0, 0, 0, 0);
  if (a > 0) {
    c = to_string(a - 1);
    memset(dp, -1, sizeof(dp));
    ans -= solve(0, 0, 0, 0);
  }
  cout << ans << "\n";
  return 0;
}
