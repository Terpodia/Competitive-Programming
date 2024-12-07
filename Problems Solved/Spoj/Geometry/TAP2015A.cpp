#pragma GCC optimize("O3,unroll-loops")

#include "bits/stdc++.h"
using namespace std;

#define fst first
#define snd second
#define pb push_back
#define len(x) (int)x.size()
#define all(x) begin(x), end(x)
#define fore(i, a, b) for (auto i = a; i < b; i++)
#define forn(i, n) fore(i, 0, n)
#define dfor(i, n) for (auto i = n; i-- > 0;)
#define dbg(x) cerr << "LINE" $ __LINE__ << ":" $ #x << "=" << x << endl;
#define raya \
  cerr << "\n-----------------------------------------------------------\n"
#define $ << " " <<

template <typename T, typename U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
  os << '(' << p.first $ p.second << ')';
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  os << "[";
  forn(i, len(v)) {
    if (i) os << ", ";
    os << v[i];
  }
  os << "]";
  return os;
}

typedef long long ll;

const int INF = 1e9;

struct Point {
  double x, y;
  Point(double _x = 0, double _y = 0) : x(_x), y(_y) {}
  bool operator==(Point p) const { return tie(x, y) == tie(p.x, p.y); }
  Point operator+(Point p) const { return Point(x + p.x, y + p.y); }
  Point operator-(Point p) const { return Point(x - p.x, y - p.y); }
  Point operator*(double d) const { return Point(x * d, y * d); }
  Point operator/(double d) const { return Point(x / d, y / d); }
  double norm2() const { return x * x + y * y; }
  double norm() const { return sqrt(norm2()); }
  Point perp() const { return Point(-y, x); }
};
bool circleInter(Point a, Point b, double r1, double r2,
                 pair<Point, Point> &out) {
  if (a == b) return false;
  Point vec = b - a;
  double d2 = vec.norm2(), sum = r1 + r2, dif = r1 - r2;
  double p = (d2 + r1 * r1 - r2 * r2) / (d2 * 2), h2 = r1 * r1 - p * p * d2;
  if (sum * sum < d2 || dif * dif > d2) return false;
  Point mid = a + vec * p, per = vec.perp() * sqrt(fmax(0, h2) / d2);
  out = {mid + per, mid - per};
  return true;
}

const double EPS = 1e-12;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  while (cin >> n) {
    Point a[n];
    double r[n];
    forn(i, n) { cin >> a[i].x >> a[i].y >> r[i]; }
    vector<Point> v;
    forn(i, n) v.pb(a[i]);
    forn(i, n) forn(j, i + 1) {
      pair<Point, Point> res;
      if (circleInter(a[i], a[j], r[i], r[j], res)) {
        v.pb(res.fst);
        v.pb(res.snd);
      }
    }
    int ans = 0;
    for (Point &p : v) {
      int cnt = 0;
      forn(i, n) {
        if ((a[i].x - p.x) * (a[i].x - p.x) + (a[i].y - p.y) * (a[i].y - p.y) -
                r[i] * r[i] <
            EPS)
          cnt++;
      }
      ans = max(ans, cnt);
    }

    cout << ans << "\n";
  }
  return 0;
}
