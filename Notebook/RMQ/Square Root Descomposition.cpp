#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

const int MAXN = 1e5, INF = 1e9;

#define forn(i, x, n) for (int i = (x); i < (int)(n); i++)

struct RMQ {
  int m, l, r;
};

RMQ rmq[MAXN];

void build(int a[], int n) {
  forn(i, 0, MAXN) rmq[i] = {INF, -1, -1};

  int k = sqrt(n);
  int index = -1;

  forn(i, 0, n) {
    if (i % k == 0) {
      index++;
      rmq[index].l = i;
    }

    rmq[index].r = i;

    rmq[index].m = min(a[i], rmq[index].m);
  }
}

int solve(int l, int r, int a[]) {
  int ans = INF;

  forn(i, 0, MAXN) {
    if (rmq[i].m == INF) break;
    if (rmq[i].l > r || rmq[i].r < l) continue;

    if (rmq[i].l >= l && rmq[i].r <= r)
      ans = min(rmq[i].m, ans);

    else if (rmq[i].l < l && rmq[i].r > r)
      forn(j, l, r + 1) ans = min(ans, a[j]);

    else if (rmq[i].l < l)
      forn(j, l, rmq[i].r + 1) ans = min(ans, a[j]);

    else
      forn(j, rmq[i].l, r + 1) ans = min(ans, a[j]);
  }

  return ans;
}

int main() {
  int n;
  cin >> n;
  int a[n];
  forn(i, 0, n) cin >> a[i];

  build(a, n);

  int q;
  cin >> q;

  while (q--) {
    int l, r;
    cin >> l >> r;
    cout << solve(l, r, a) << "\n";
  }

  return 0;
}
