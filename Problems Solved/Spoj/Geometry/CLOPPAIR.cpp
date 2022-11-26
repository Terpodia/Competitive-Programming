#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;

typedef long long ll;

struct pt {
  ll x, y;
  int id;

  pt operator-(const pt& b) { return {x - b.x, y - b.y, 0}; }

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

int n, x, y;
vector<pt> a, t;
ll z;

void upd(pt& q, pt& r) {
  ll d = (r - q).sqr_norm();
  if (d < z) z = d, x = q.id, y = r.id;
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
    if (abs(a[i].x - mx) * abs(a[i].x - mx) < z) {
      for (int j = sz - 1; j >= 0 && (a[i].y - t[j].y) * (a[i].y - t[j].y) < z;
           j--)
        upd(a[i], t[j]);

      t[sz++] = a[i];
    }
  }
}

int main() {
  scanf("%d", &n);

  a = vector<pt>(n);
  t = vector<pt>(n);

  for (int i = 0; i < n; i++) {
    scanf("%lld %lld", &a[i].x, &a[i].y);
    a[i].id = i;
  }

  z = INF;
  sort(a.begin(), a.end(), cmp_x());
  solve(0, n);

  if (x > y) swap(x, y);
  printf("%d %d %.6lf\n", x, y, sqrt(z));

  return 0;
}
