/*
*************************************************************
"Si puedes imaginarlo, puedes programarlo" Alejandro Taboada.
*************************************************************
*/

#include <cstring>
#include <iostream>
using namespace std;
using ll = long long;

#define forn(i, x, n) for (int i = (x); i < (int)(n); i++)

void setIO(string name = "") { cin.tie(0)->sync_with_stdio(0); }

const int MAXN = 207;
const ll INF = 1e18;
const ll check = -1e16;

int n, k, x;
ll a[MAXN], dp[MAXN][MAXN][MAXN];

ll solve(int i, int s, int u) {
  if (i - u + 1 > k) return -INF;
  if (i == n) return 0;

  ll& ret = dp[i][s][u];
  if (ret != -1) return ret;

  ll x1 = -INF, x2 = -INF;
  if (s < x) x1 = a[i] + solve(i + 1, s + 1, i + 1);
  x2 = solve(i + 1, s, u);

  return ret = max(x1, x2);
}

int main() {
  setIO();
  cin >> n >> k >> x;
  forn(i, 0, n) cin >> a[i];
  memset(dp, -1, sizeof(dp));

  ll ans = solve(0, 0, 0);
  (ans <= check) ? cout << "-1\n" : cout << ans << "\n";

  return 0;
}
