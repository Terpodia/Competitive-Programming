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

const int INF = 1e9 + 10;

int n;
ll w, x[20];

int dp[1 << 20];

int solve(int msk);

int go(int cur, int msk, ll acc, ll lo) {
  if (msk == 0) {
    if (acc + lo <= w) return INF;
    return 1 + solve(cur);
  }

  int j = msk & (-msk);
  int ret = go(cur, msk ^ j, acc, min(lo, x[__builtin_ctz(j)]));
  acc += x[__builtin_ctz(j)];
  if (acc <= w) ret = min(ret, go(cur ^ j, msk ^ j, acc, lo));
  return ret;
}

int solve(int msk) {
  int &ret = dp[msk];
  if (ret != -1) return ret;
  ret = INF;
  if (msk == 0) return ret = 0;
  int j = __builtin_ctz(msk);
  return ret = go(msk ^ (1 << j), msk ^ (1 << j), x[j], INF);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> w;
  forn(i, n) cin >> x[i];
  sort(x, x + n, greater<ll>());
  memset(dp, -1, sizeof(dp));
  cout << solve((1 << n) - 1) << "\n";
  return 0;
}
