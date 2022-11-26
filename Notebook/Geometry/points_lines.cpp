#include <bits/stdc++.h>
using namespace std;

const double INF = 1e9;
const double EPS = 1e-9;

double deg2rad(double angle) { return angle * M_PI / 180.0; }
double rad2deg(double angle) { return angle * 180.0 / M_PI; }

struct point {
  double x, y;
  point() { x = y = 0; }
  point(double _x, double _y) : x(_x), y(_y) {}
  bool operator<(const point& p) const {
    if (fabs(x - p.x) > EPS) return x < p.x;
    return y < p.y;
  }
  bool operator==(const point& p) const {
    return (fabs(x - p.x) < EPS && fabs(y - p.y) < EPS);
  }
};

double dist(point p1, point p2) { return hypot(p1.x - p2.x, p1.y - p2.y); }

point rotate(point p, double theta) {
  double angle = deg2rad(theta);
  return point(p.x * cos(angle) - p.y * sin(angle),
               p.x * sin(angle) + p.y * cos(angle));
}

struct line {
  double a, b, c;
  line() { a = b = c = 0; }
  line(double _a, double _b, double _c) : a(_a), b(_b), c(_c) {}
  line(point p1, point p2) {
    if (fabs(p1.x - p2.x) < EPS)
      a = 1, b = 0, c = -p1.x;
    else {
      double m = (p1.y - p2.y) / (p1.x - p2.x);
      a = -m, b = 1, c = m * p1.x - p1.y;
    }
  }
  line(point p, double m) { a = -m, b = 1, c = m * p.x - p.y; }
  bool operator==(const line& l) const {
    return (fabs(a - l.a) < EPS && fabs(b - l.b) < EPS && fabs(c - l.c) < EPS);
  }
};

bool areParalell(line l1, line l2) {
  return (fabs(l1.a - l2.a) < EPS && fabs(l1.b - l2.b) < EPS);
}

bool arePerpendicular(line l1, line l2) {
  if (areParalell(l1, l2)) return false;
  if (fabs(l1.b) < EPS) return fabs(l2.a) < EPS;
  if (fabs(l1.a) < EPS) return fabs(l2.b) < EPS;
  return fabs(-l2.a - (1 / l1.a)) < EPS;
}

bool areIntersect(line l1, line l2, point& p) {
  if (areParalell(l1, l2)) return false;

  p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l2.b * l1.a);
  if (fabs(l1.b) > EPS)
    p.y = -(l1.c + l1.a * p.x);
  else
    p.y = -(l2.c + l2.a * p.x);
  return true;
}

struct vec {
  double x, y;
  vec(double _x, double _y) : x(_x), y(_y) {}
  vec(point a, point b) { x = b.x - a.x, y = b.y - a.y; }
};

vec scale(vec v, double s) { return vec(v.x * s, v.y * s); }

point translate(point p, vec v) { return point(p.x + v.x, p.y + v.y); }

double norm_sq(vec v) { return v.x * v.x + v.y * v.y; }

double dot(vec a, vec b) { return a.x * b.x + a.y * b.y; }

double cross(vec a, vec b) { return a.x * b.y - a.y * b.x; }

bool ccw(point p, point q, point r) {
  return cross(vec(p, q), vec(p, r)) > EPS;
}

double angle(point a, point o, point b) {
  vec oa(o, a), ob(o, b);
  return rad2deg(acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob))));
}

double distToLine(point a, point b, point p, point& c) {
  vec ab(a, b), ap(a, p);
  double u = dot(ab, ap) / norm_sq(ab);
  c = translate(a, scale(ab, u));
  return dist(p, c);
}

double distToLineSegment(point a, point b, point p, point& c) {
  vec ab(a, b), ap(a, p);
  double u = dot(ab, ap) / norm_sq(ab);
  if (u < EPS) {
    c.x = a.x, c.y = a.y;
    return dist(p, a);
  }
  if (u > 1.0) {
    c.x = b.x, c.y = b.y;
    return dist(p, b);
  }
  return distToLine(a, b, p, c);
}

void test_line() {
  printf("=============TESTING LINE===========\n");
  double x1, y1, x2, y2;
  scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
  line l1(point(x1, y1), point(x2, y2));
  scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
  line l2(point(x1, y1), point(x2, y2));

  if (l1 == l2)
    printf("The lines are equal\n");
  else if (areParalell(l1, l2))
    printf("The lines are paralell\n");
  else {
    point p;
    areIntersect(l1, l2, p);
    printf("The intersection point is (%lf, %lf)\n", p.x, p.y);
    if (arePerpendicular(l1, l2)) printf("The lines are perpendicular\n");
  }
}

void test_vec() {
  printf("=============TESTING VECTOR===========\n");
  point p, q, r;
  scanf("%lf %lf %lf %lf %lf %lf", &p.x, &p.y, &q.x, &q.y, &r.x, &r.y);
  if (ccw(p, q, r)) printf("Counter Clockwise\n");
  printf("The angle between qp and qr is %lf\n", angle(p, q, r));

  point c;
  printf("The minimun distance from r to line pq is equal to %lf\n",
         distToLine(p, q, r, c));

  printf("The minimun distance from r to line segment pq is equal to %lf\n",
         distToLineSegment(p, q, r, c));
}

int main() {
  test_vec();
  return 0;
}
