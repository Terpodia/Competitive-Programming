#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

#define sz(x) (int)x.size()

const int MAXN = 107;
const int MAXM = 10007;
const int INF = 1e9;

int n, m, dp[MAXM];
vector<int> a[MAXN], b[MAXN];

void calc(int pos, int size) {
  int lo = 1e9, acc = 0, s = 0;
  for (int i : a[pos]) s += i;

  for (int i = 0; i < sz(a[pos]) - size; i++) acc += a[pos][i];

  lo = acc;
  int l = 0;

  for (int i = sz(a[pos]) - size; i < sz(a[pos]); i++) {
    acc -= a[pos][l];
    acc += a[pos][i];
    lo = min(lo, acc);
    l++;
  }

  b[pos][size] = s - lo;
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    int k, d;
    scanf("%d", &k);
    for (int j = 0; j < k; j++) {
      scanf("%d", &d);
      a[i].push_back(d);
    }
    b[i] = vector<int>(k + 1, 0);
  }

  for (int i = 0; i < n; i++)
    for (int j = 1; j <= sz(a[i]); j++) calc(i, j);

  for (int i = 1; i <= n; i++) {
    for (int k = m; k >= 0; k--) {
      for (int j = 0; j < sz(b[i - 1]); j++) {
        if (j > k) continue;
        dp[k] = max(dp[k], dp[k - j] + b[i - 1][j]);
      }
    }
  }

  printf("%d\n", dp[m]);

  return 0;
}
