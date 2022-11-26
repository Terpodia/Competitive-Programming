#include <cstdio>

typedef long long ll;

ll r, s;
int x, y, w;

ll dp[12][12];

ll solve(int i, int j) {
  if (i == y) return (j >= x) ? (ll)w : 0;
  ll& ret = dp[i][j];
  if (ret != -1) return ret;
  return ret =
             ((s - r + 1) * solve(i + 1, j + 1)) + ((r - 1) * solve(i + 1, j));
}

int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    scanf("%lld%lld%d%d%d", &r, &s, &x, &y, &w);
    for (int i = 0; i < 12; i++)
      for (int j = 0; j < 12; j++) dp[i][j] = -1;

    ll den = 1;
    for (int i = 0; i < y; i++) den *= s;
    ll num = solve(0, 0);
    if (num > den)
      puts("yes");
    else
      puts("no");
  }
  return 0;
}
