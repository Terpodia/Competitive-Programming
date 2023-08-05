#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 8;

typedef long long ll;

int main() {
  ll p[31];
  p[0] = 1;
  for (int i = 1; i <= 30; i++) p[i] = p[i - 1] * (ll)2;

  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    ll k;
    scanf("%d%lld", &n, &k);
    ll a[n];
    for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
    ll dp[n + 1][31];
    memset(dp, 0, sizeof(dp));
    for (int i = n - 1; i >= 0; i--) {
      for (int j = 29; j >= 0; j--) {
        dp[i][j] = max(dp[i + 1][j] - k + a[i] / p[j],
                       dp[i + 1][j + 1] + a[i] / p[j + 1]);
      }
    }
    printf("%lld\n", dp[0][0]);
  }
  return 0;
}
