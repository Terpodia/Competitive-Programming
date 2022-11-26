#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

typedef long long ll;

const int MAXN = 2e5 + 7;
const ll INF = 1e18;

int n;
ll a, b, x[MAXN], pref[MAXN], suff[MAXN];

void solve() {
  ll ans = INF;
  for (int i = 0; i < n; i++) {
    ans = min(ans, (x[i] * a) + (pref[i] + suff[i + 1]) - (x[i] * b * (n - i)));
  }
  printf("%lld\n", ans);
}

int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    scanf("%d%lld%lld", &n, &a, &b);
    x[0] = 0;
    for (int i = 1; i <= n; i++) scanf("%lld", x + i);
    memset(pref, 0, sizeof(pref));
    memset(suff, 0, sizeof(suff));
    for (int i = 1; i <= n; i++) {
      pref[i] = pref[i - 1] + (x[i] - x[i - 1]) * b;
    }
    for (int i = n; i >= 0; i--) {
      suff[i] = suff[i + 1] + x[i] * b;
    }
    solve();
  }
  return 0;
}
