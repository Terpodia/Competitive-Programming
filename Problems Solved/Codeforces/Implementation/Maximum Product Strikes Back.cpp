#include <iostream>
using namespace std;

#define rep(i, x, n) \
  for (__typeof(n) i = (x); i != (n); i += 1 - 2 * ((x) > (n)))

const int MAXN = 2e5 + 7;

int n, a[MAXN];

void solve() {
  int l = 0, hi = 0;
  pair<int, int> ans = {n, 0};

  while (l < n + 1) {
    int r = l + 1;
    while (r < n + 2 && a[r] != 0) r++;

    int cntTwo = 0, cntNegative = 0, firstNegative = -1, lastNegative = -1,
        firstNegativeCost = 0, lastNegativeCost = 0;

    rep(i, l + 1, r) if (abs(a[i]) == 2) cntTwo++;
    rep(i, l + 1, r) if (a[i] < 0) cntNegative++;
    rep(i, l + 1, r) {
      if (abs(a[i]) == 2) firstNegativeCost++;
      if (a[i] < 0) {
        firstNegative = i;
        break;
      }
    }
    rep(i, r - 1, l) {
      if (abs(a[i]) == 2) lastNegativeCost++;
      if (a[i] < 0) {
        lastNegative = i;
        break;
      }
    }
    if (cntNegative % 2 != 0) {
      cntTwo -= min(firstNegativeCost, lastNegativeCost);
      if (cntTwo > hi) {
        hi = cntTwo;
        if (firstNegativeCost < lastNegativeCost)
          ans = {firstNegative, n - r + 1};
        else
          ans = {l, n - lastNegative + 1};
      }
    } else if (cntTwo > hi)
      hi = cntTwo, ans = {l, n - r + 1};

    l = r;
  }
  printf("%d %d\n", ans.first, ans.second);
}

int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    scanf("%d", &n);
    a[0] = 0;
    rep(i, 1, n + 1) scanf("%d", a + i);
    a[n + 1] = 0;
    solve();
  }
  return 0;
}

