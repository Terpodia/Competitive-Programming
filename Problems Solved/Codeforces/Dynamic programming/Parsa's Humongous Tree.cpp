#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int MAXN = 1e5;
int n;
ll a[MAXN][2], dp[MAXN][2];
vector<int> G[MAXN];

ll solve(int val, int u, int v) {
  ll &ret = dp[u][val];
  if (ret != -1) return ret;

  ret = 0;

  for (int i : G[u]) {
    if (i == v) continue;
    ret += max(abs(a[u][val] - a[i][0]) + solve(0, i, u),
               abs(a[i][1] - a[u][val]) + solve(1, i, u));
  }

  return ret;
}

int main() {
  int t;
  scanf("%d", &t);

  while (t--) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%lld%lld", &a[i][0], &a[i][1]);

    for (int i = 0; i < n - 1; i++) {
      int u, v;
      scanf("%d%d", &u, &v);
      G[u - 1].push_back(v - 1);
      G[v - 1].push_back(u - 1);
    }

    memset(dp, -1, sizeof(dp));

    printf("%lld\n", max(solve(0, 0, -1), solve(1, 0, -1)));

    for (int i = 0; i < n; i++) G[i].clear();
  }

  return 0;
}
