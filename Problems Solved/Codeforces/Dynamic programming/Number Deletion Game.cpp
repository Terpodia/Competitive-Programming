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

int n, k;
ll a[401], pref[401], dp[401][401];

ll solve(int l, int r) {
  ll &ret = dp[l][r];
  if (ret != -1) return ret;
  ret = 0;

  int m = k - (l + n - 1 - r) / 2;
  if (m == 0) return ret;

  fore(i, l, r) {
    if (m <= r - i - 1 && m <= i - l) {
      ret = max(ret, (pref[i + 1 + m] - pref[i + 1]) -
                         (pref[i + 1] - pref[i + 1 - m]));
    } else if (r - i - 1 <= i - l) {
      ret = max(ret, (pref[r + 1] - pref[i + 1]) -
                         (pref[i + 1] - pref[i - r + i + 1]) +
                         solve(l, i - r + i));
    } else {
      ret = max(ret, (pref[i + 1 + i - l + 1] - pref[i + 1]) -
                         (pref[i + 1] - pref[l]) + solve(i + 1 + i - l + 1, r));
    }
  }
  return ret;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  forn(i, n) cin >> a[i];
  sort(a, a + n);
  fore(i, 1, n + 1) pref[i] = pref[i - 1] + a[i - 1];
  memset(dp, -1, sizeof(dp));
  cout << solve(0, n - 1) << "\n";
  return 0;
}
