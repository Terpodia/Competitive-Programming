#include <cstdio>

typedef long long ll;

#define FOR(i, x, n) for (int i = (x); i < (int)(n); i++)
#define RFOR(i, x, n) for (int i = (x); i > (int)(n); i--)

const ll MOD = 1e9 + 7;
int xD;
ll comb[1007][1007];

void calc() {
  FOR(i, 0, 1007) {
    FOR(k, 0, 1007) {
      if (k > i)
        break;
      else if (k == 0 || k == i)
        comb[i][k] = 1;
      else
        comb[i][k] = (comb[i - 1][k] + comb[i - 1][k - 1]) % MOD;
    }
  }
}

int main() {
  int k;
  xD = scanf("%d", &k);
  int a[k];
  FOR(i, 0, k) xD = scanf("%d", a + i);
  calc();

  int n = 0;
  ll ans = 1;
  FOR(i, 0, k) n += a[i];

  RFOR(i, k - 1, -1) {
    ans = (ans * comb[n - 1][a[i] - 1]) % MOD;
    n -= a[i];
  }

  printf("%lld\n", ans);

  return 0;
}
