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

const int MAXN = 5e5 + 10;

const int INF = 1e9 + 10;

int n, k;

int a[MAXN];

int f(int m) {
  int b[n];
  forn(i, n) b[i] = (a[i] >= m) ? 1 : -1;

  int dp[n + 1];
  dp[0] = 0;
  fore(i, 1, n + 1) {
    if ((i - 1) % k == 0) {
      dp[i] = b[i - 1];
      if (i >= k) dp[i] = max(dp[i], dp[i - k]);
    } else {
      dp[i] = dp[i - 1] + b[i - 1];
      if (i >= k) dp[i] = max(dp[i], dp[i - k]);
    }
  }
  return dp[n];
}

void solve() {
  cin >> n >> k;
  forn(i, n) cin >> a[i];
  int l = 0, r = INF;
  while (r > l) {
    int mid = l + (r - l + 1) / 2;
    if (f(mid) > 0)
      l = mid;
    else
      r = mid - 1;
  }
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
