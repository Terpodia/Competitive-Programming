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

const ll INF = 1e13;

const int MAXN = 3e5 + 10;

const ll MOD = 1e9 + 7;

int n, m;

ll a[MAXN], b[MAXN], pref[MAXN], calc[MAXN], suff[MAXN];

vector<vector<ll>> dp;

ll ans;

ll f(int i, int j) {
  ll &ret = dp[i][j];
  if (ret != -1) return ret;

  if (i == n) return ret = 0;

  ret = INF;
  if (a[i] > b[j]) return ret;

  int l = i, r = n - 1;
  while (r > l) {
    int mid = l + (r - l + 1) / 2;
    if (pref[mid + 1] - pref[i] <= b[j])
      l = mid;
    else
      r = mid - 1;
  }

  ret = f(l + 1, j) + (ll)m - (ll)j - 1LL;
  if (j < m - 1) ret = min(ret, f(i, j + 1));

  return ret;
}

ll cnt(int i, int j, ll cur = 0) {
  if (i == n) return 1;

  if (j == m - 1) return calc[n - i];

  int l = i, r = n - 1;

  while (r > l) {
    int mid = l + (r - l + 1) / 2;
    if (pref[mid + 1] - pref[i] <= b[j])
      l = mid;
    else
      r = mid - 1;
  }

  ll c = (ll)m - (ll)j - 1LL;

  ll res = 0;

  if (dp[l + 1][j] + c + cur == ans) res += cnt(l + 1, j, cur + c), res %= MOD;
  if (dp[i][j + 1] + cur == ans) res += cnt(i, j + 1, cur), res %= MOD;
  return res;
}

void solve() {
  cin >> n >> m;
  forn(i, n) cin >> a[i];
  forn(i, m) cin >> b[i];

  dp = vector<vector<ll>>(n + 10, vector<ll>(m + 10, -1));
  fore(i, 1, n + 1) pref[i] = pref[i - 1] + a[i - 1];

  suff[n] = -INF;
  dfor(i, n) suff[i] = max(suff[i + 1], a[i]);

  calc[0] = 1;
  ll cur[n + 1];
  cur[0] = 1;

  fore(i, 1, n + 1) {
    if (a[n - i] > b[m - 1]) break;

    int l = n - i, r = n - 1;
    while (r > l) {
      int mid = l + (r - l + 1) / 2;
      if (pref[mid + 1] - pref[n - i] <= b[m - 1])
        l = mid;
      else
        r = mid - 1;
    }

    int k = l - (n - i) + 1;

    calc[i] = cur[i - 1] - ((i - k > 0) ? (cur[i - k - 1]) : (0));
    calc[i] %= MOD, calc[i] += MOD, calc[i] %= MOD;

    cur[i] = cur[i - 1] + calc[i];
    cur[i] %= MOD;
  }

  ans = f(0, 0);
  if (ans >= INF)
    cout << "-1\n";
  else {
    cout << ans << " ";
    cout << cnt(0, 0) << "\n";
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
