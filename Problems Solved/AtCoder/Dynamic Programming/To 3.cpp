#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
using ll = long long;

#define INF 1e9
#define sz(x) (int)x.size()

void setIO() { cin.tie(0)->sync_with_stdio(0); }

string N;

int dp[1 << 18];

int solve(int msk) {
  if (__builtin_popcount(msk) == sz(N)) return INF;

  int& ret = dp[msk];

  if (ret != -1) return ret;

  ll pot = 1, num = 0;

  for (int i = sz(N) - 1; i >= 0; i--) {
    if (msk & (1 << i)) continue;
    num += (ll)(N[i] - '0') * pot;
    pot *= 10;
  }

  if (num % 3 == 0) return ret = 0;

  ret = INF;

  for (int i = 0; i < sz(N); i++) {
    if (msk & (1 << i)) continue;
    int nmsk = msk | (1 << i);
    ret = min(ret, 1 + solve(nmsk));
  }

  return ret;
}

int main() {
  setIO();
  cin >> N;

  memset(dp, -1, sizeof(dp));
  int ans = solve(0);
  (ans >= INF) ? puts("-1") : printf("%d\n", ans);

  return 0;
}
