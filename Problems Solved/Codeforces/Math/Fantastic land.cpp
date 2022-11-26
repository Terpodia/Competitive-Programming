#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;

typedef long long ll;

struct pt {
  ll x, y;

  pt operator-(const pt& b) { return {x - b.x, y - b.y}; }

  ll sqr_norm() { return (x * x) + (y * y); }
};

struct cmp_x {
  bool operator()(const pt& a, const pt& b) const {
    return (a.x < b.x || (a.x == b.x && a.y < b.y));
  }
};

struct cmp_y {
  bool operator()(const pt& a, const pt& b) const {
    return (a.y < b.y || (a.y == b.y && a.x < b.x));
  }
};

const ll MAX = 1e4 * 1e4, INF = 1e18;

int n;
vector<pt> a, t;
ll min_dist, ans;

void upd(pt& q, pt& r) {
  ll d = (r - q).sqr_norm();
  if (d < min_dist)
    ans = min_dist, min_dist = d;
  else if (d > min_dist && d < ans)
    ans = d;
}

void solve(int l, int r) {
  if (r - l <= 3) {
    for (int i = l; i < r; i++)
      for (int j = i + 1; j < r; j++) upd(a[i], a[j]);

    sort(a.begin() + l, a.begin() + r, cmp_y());
    return;
  }

  int m = (l + r) / 2;
  ll mx = a[m].x;

  solve(l, m);
  solve(m, r);

  merge(a.begin() + l, a.begin() + m, a.begin() + m, a.begin() + r, t.begin(),
        cmp_y());
  copy(t.begin(), t.begin() + r - l, a.begin() + l);

  int sz = 0;

  for (int i = l; i < r; i++) {
    if (abs(a[i].x - mx) * abs(a[i].x - mx) < ans) {
      for (int j = sz - 1;
           j >= 0 && (a[i].y - t[j].y) * (a[i].y - t[j].y) < ans; j--)
        upd(a[i], t[j]);

      t[sz++] = a[i];
    }
  }
}

int main() {
  scanf("%d", &n);

  a = vector<pt>(n);
  t = vector<pt>(n);

  for (int i = 0; i < n; i++) scanf("%lld %lld", &a[i].x, &a[i].y);

  min_dist = INF, ans = INF;
  sort(a.begin(), a.end(), cmp_x());
  solve(0, n);

  printf("%.8lf\n", sqrt(ans));

  return 0;
}
