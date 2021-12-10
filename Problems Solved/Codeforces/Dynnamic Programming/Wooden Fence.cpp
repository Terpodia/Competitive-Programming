#include <cstdio>
#include <cstring>

typedef long long ll;

#define FOR(i, x, n) for (int i = (x); i < (int)(n); i++)

const ll MOD = 1e9 + 7;
int n, l, w[100], h[100], aux;

ll dp[3007][100][3];

ll solve(int cnt, int j, int t) {
  if (cnt > l)
    return 0;

  ll &ret = dp[cnt][j][t];
  if (cnt == l)
    return ret = 1;

  if (ret != -1)
    return ret;

  ret = 0;

  if (t == 2) {
    FOR(i, 0, n) FOR(k, 0, 2) {
      ll s = (k == 0) ? solve(cnt + w[i], i, k) : solve(cnt + h[i], i, k);
      ret = (ret + s) % MOD;
      if (w[i] == h[i])
        break;
    }
  }

  else {
    int width = (t == 0) ? h[j] : w[j];

    FOR(i, 0, n) FOR(k, 0, 2) {
      if (i == j)
        break;

      int len = (k == 0) ? w[i] : h[i];
      if (len == width)
        ret = (ret + solve(cnt + len, i, k)) % MOD;

      if (w[i] == h[i])
        break;
    }
  }

  return ret;
}

int main() {
  memset(dp, -1, sizeof(dp));
  aux = scanf("%d%d", &n, &l);
  FOR(i, 0, n) aux = scanf("%d%d", w + i, h + i);
  printf("%lld\n", solve(0, 0, 2));

  return 0;
}