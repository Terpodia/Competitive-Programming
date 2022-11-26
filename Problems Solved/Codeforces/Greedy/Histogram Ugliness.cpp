#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
using ll = long long;

const int MAXN = 4e5;

int n;
ll a[MAXN];

ll solve() {
  if (n == 1) return a[0];

  ll cnt = 0;

  for (int i = 0; i < n; i++) {
    if (i == 0 && i < n - 1 && a[i] > a[i + 1]) {
      cnt += a[i] - a[i + 1];
      a[i] = a[i + 1];
    }

    else if (i == n - 1 && i > 0 && a[i] > a[i - 1]) {
      cnt += a[i] - a[i - 1];
      a[i] = a[i - 1];
    }

    else if (i > 0 && i < n - 1 && a[i] > a[i - 1] && a[i] > a[i + 1]) {
      cnt += a[i] - max(a[i - 1], a[i + 1]);
      a[i] = max(a[i - 1], a[i + 1]);
    }
  }

  ll ret = cnt;

  ret += a[0] + a[n - 1];

  for (int i = 0; i < n - 1; i++) ret += abs(a[i] - a[i + 1]);

  return ret;
}

int main() {
  int t;
  scanf("%d", &t);

  while (t--) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%lld", a + i);

    printf("%lld\n", solve());
  }

  return 0;
}
