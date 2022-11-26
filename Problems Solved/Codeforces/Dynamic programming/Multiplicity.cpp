// https://codeforces.com/problemset/problem/1061/C

#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define f first
#define s second
#define rep(i, x, n) for (__typeof(n) i = (x); i != (n); i += 1 - 2 * (x > n))
#define dbg(x) cout << #x << "=" << x << " ";
#define line cout << "\n=================================================\n"

const int MOD = 1e9 + 7;

int sum(int a, int b) {
  if (a >= MOD) a -= MOD;
  if (b >= MOD) b -= MOD;
  int ret = a + b;
  if (ret >= MOD) ret -= MOD;
  return ret;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n;
  cin >> n;
  int a[n];
  rep(i, 0, n) cin >> a[i];

  int hi = *max_element(a, a + n), dp[hi + 1];
  memset(dp, 0, sizeof(dp));
  dp[0] = 1;
  rep(i, 1, n + 1) {
    vector<int> d;
    for (int j = 1; j * j <= a[i - 1]; j++) {
      if (a[i - 1] % j == 0) {
        d.push_back(j);
        if (j * j != a[i - 1]) d.push_back(a[i - 1] / j);
      }
    }
    rep(j, sz(d) - 1, -1) dp[d[j]] = sum(dp[d[j]], dp[d[j] - 1]);
  }
  int ans = 0;
  rep(i, 1, hi + 1) ans = sum(ans, dp[i]);
  cout << ans << "\n";
  return 0;
}
