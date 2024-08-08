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

ll k;

vector<ll> b, dp[2];

ll f(int i, int flag) {
  ll &ret = dp[flag][i];
  if (ret != -1) return ret;

  if (i >= len(b)) return ret = (flag == 0) ? INF : 0;

  ret = INF;

  if (i < len(b) - 1) ret = (b[i + 1] - b[i]) / k + f(i + 2, flag);

  if (flag == 0) {
    ret = min(ret, f(i + 1, 1));
    if (i + 2 < len(b)) ret = min(ret, (b[i + 2] - b[i]) / k + f(i + 3, 1));
  }
  return ret;
}

void solve() {
  int n;
  cin >> n >> k;
  ll a[n];
  forn(i, n) cin >> a[i];

  map<ll, vector<ll>> cnt;
  forn(i, n) cnt[a[i] % k].push_back(a[i]);
  for (auto &[x, y] : cnt) sort(all(y));

  int odd = 0;
  for (auto &[x, y] : cnt) {
    if (len(y) % 2 == 1) odd++;
  }
  if (odd > 1) {
    cout << "-1\n";
    return;
  }
  ll ans = 0;
  for (auto &[x, y] : cnt) {
    // dbg(y);
    if (len(y) % 2 == 0) {
      for (int i = 0; i < len(y); i += 2) ans += (y[i + 1] - y[i]) / k;
    } else {
      b = y;
      // dbg(b);
      dp[0] = dp[1] = vector<ll>(len(b) + 100, -1);
      ans += f(0, 0);
    }
  }
  cout << ans << "\n";
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
