//-Si puedes imaginarlo, puedes programarlo- Alejandro Taboada
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define fst first
#define snd second
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define rep(i, x, n) \
  for (__typeof(n) i = (x); i != (n); i += 1 - 2 * ((x) > (n)))
#define dbg(x) cout << #x << "=" << x << " ";
#define line cout << "\n........................................\n";

const int INF = 1e9;

struct point {
  int x, y;
};

point a[3];

int dist(point p1, point p2) {
  return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

int sqr(int x) { return x * x; }

bool calc(point& p1, point& p2, point& p3, point& p4, int& y1, int& y2) {
  int r, v;

  if (p1.y == INF) {
    r = dist(p3, p4) - sqr(p1.x - p2.x);
    v = p2.y;
    if (r < 0 || (int)floor(sqrt(r)) != (int)ceil(sqrt(r))) return false;
    y1 = (int)floor(sqrt(r)) + v, y2 = -(int)floor(sqrt(r)) + v;
  }

  else if (p2.y == INF) {
    r = dist(p3, p4) - sqr(p2.x - p1.x);
    v = p1.y;
    if (r < 0 || (int)floor(sqrt(r)) != (int)ceil(sqrt(r))) return false;
    y1 = (int)floor(sqrt(r)) + v, y2 = -(int)floor(sqrt(r)) + v;
  }

  else if (p3.y == INF) {
    r = dist(p1, p4) - sqr(p3.x - p2.x);
    v = p2.y;
    if (r < 0 || (int)floor(sqrt(r)) != (int)ceil(sqrt(r))) return false;
    y1 = (int)floor(sqrt(r)) + v, y2 = -(int)floor(sqrt(r)) + v;
  }

  else {
    r = dist(p2, p3) - sqr(p4.x - p1.x);
    v = p1.y;
    if (r < 0 || (int)floor(sqrt(r)) != (int)ceil(sqrt(r))) return false;
    y1 = (int)floor(sqrt(r)) + v, y2 = -(int)floor(sqrt(r)) + v;
  }

  return true;
}

bool ok(point& p1, point& p2, point& p3, point& p4) {
  if (dist(p1, p2) != dist(p3, p4)) return false;
  if (dist(p2, p3) != dist(p1, p4)) return false;

  if (p1.x != p2.x) {
    if (p3.x == p4.x)
      return false;

    else if ((p1.y - p2.y) * (p3.x - p4.x) != (p3.y - p4.y) * (p1.x - p2.x))
      return false;

  } else {
    if (p3.x != p4.x) return false;
  }

  if (p2.x != p3.x) {
    if (p1.x == p4.x)
      return false;

    else if ((p2.y - p3.y) * (p1.x - p4.x) != (p1.y - p4.y) * (p2.x - p3.x))
      return false;

  } else {
    if (p1.x != p4.x) return false;
  }

  return true;
}

int main() {
  rep(i, 0, 3) scanf("%d%d", &a[i].x, &a[i].y);

  set<pair<int, int>> ans;

  rep(x, -4001, 4001) {
    point p[4];
    p[0] = a[0], p[1] = a[1], p[2] = a[2], p[3] = {x, INF};
    int perm[4] = {0, 1, 2, 3};

    do {
      p[3].y = INF;

      int y1, y2;

      if (!calc(p[perm[0]], p[perm[1]], p[perm[2]], p[perm[3]], y1, y2))
        continue;

      p[3].y = y1;
      if (ok(p[perm[0]], p[perm[1]], p[perm[2]], p[perm[3]])) {
        ans.insert({p[3].x, p[3].y});
      }

      p[3].y = y2;
      if (ok(p[perm[0]], p[perm[1]], p[perm[2]], p[perm[3]])) {
        ans.insert({p[3].x, p[3].y});
      }

    } while (next_permutation(perm, perm + 4));
  }

  printf("%d\n", sz(ans));
  for (auto& [x, y] : ans) printf("%d %d\n", x, y);

  return 0;
}

