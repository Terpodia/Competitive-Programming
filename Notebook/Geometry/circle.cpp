#include <bits/stdc++.h>
using namespace std;

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

struct point_i {
  int x, y;
  point_i() { x = y = 0; }
  point_i(int _x, int _y) : x(_x), y(_y) {}
};

int insideCircle(const point_i& p, const point_i& c, int r) {
  int d = (p.x - c.x) * (p.x - c.x) + (p.y - c.y) * (p.y - c.y);
  return (d < r * r) ? 1 : ((d == r * r) ? 0 : -1);
}

double perimeter(double r) { return 2 * M_PI * r; }

double area(double r) { return M_PI * r * r; }

double arcLen(double theta, double r) { return (theta / 360.0) * perimeter(r); }

double chordLen(double theta, double r) {
  return 2 * r * sin(deg2rad(theta / 2));
}

double sectorSz(double theta, double r) { return (theta / 360.0) * area(r); }

double segmentSz(double theta, double r) {
  return sectorSz(theta, r) -
         ((chordLen(theta, r) * cos(deg2rad(theta)) * r) / 2.0);
}

bool circle2PtsRad(point p1, point p2, double r, point& c) {
  double dSqr = (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
  double h = r * r / dSqr - 0.25;
  if (h < EPS) return false;
  h = sqrt(h);
  c.x = (p1.x + p2.x) / 2 + (p1.y - p2.y) * h;
  c.y = (p1.y + p2.y) / 2 + (p2.x - p1.x) * h;
  return true;
}

int main() {
  // circle equation, inside, border, outside
  point_i pt(2, 2);
  int r = 7;
  point_i inside(8, 2);
  printf("%d\n", insideCircle(inside, pt, r));  // 1, inside
  point_i border(9, 2);
  printf("%d\n", insideCircle(border, pt, r));  // 0, at border
  point_i outside(10, 2);
  printf("%d\n", insideCircle(outside, pt, r));  // -1, outside

  printf("Diameter = %d\n", 2 * r);
  printf("Circumference (Perimeter) = %.2lf\n", perimeter(r));
  printf("Area of circle = %.2lf\n", area(r));

  printf("Length of arc   (central angle = 60 degrees) = %.2lf\n",
         arcLen(60, r));
  printf("Length of chord (central angle = 60 degrees) = %.2lf\n",
         chordLen(60, r));
  printf("Area of sector  (central angle = 60 degrees) = %.2lf\n",
         sectorSz(60, r));
  printf("Area of segment  (central angle = 60 degrees) = %.2lf\n",
         segmentSz(60, r));

  point p1;
  point p2(0.0, -1.0);
  point ans;
  circle2PtsRad(p1, p2, 2.0, ans);
  printf("One of the center is (%.2lf, %.2lf)\n", ans.x, ans.y);
  circle2PtsRad(p2, p1, 2.0, ans);  // reverse p1 with p2
  printf("The other center  is (%.2lf, %.2lf)\n", ans.x, ans.y);

  return 0;
}

