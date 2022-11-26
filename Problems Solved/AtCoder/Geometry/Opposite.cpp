#include <cmath>
#include <iostream>
using namespace std;

#define PI 3.14159265359

int main() {
  double N;
  scanf("%lf", &N);

  double x0, y0, x, y;
  scanf("%lf%lf%lf%lf", &x0, &y0, &x, &y);

  double xc = x0 + (x - x0) / 2;
  double yc = y0 + (y - y0) / 2;

  double x0_relative = (x0 - xc);
  double y0_relative = (y0 - yc);

  double angle = 360 / N;

  double x1_relative =
      x0_relative * cos(angle * PI / 180) - y0_relative * sin(angle * PI / 180);
  double y1_relative =
      x0_relative * sin(angle * PI / 180) + y0_relative * cos(angle * PI / 180);

  double x1 = (x1_relative + xc);
  double y1 = (y1_relative + yc);

  printf("%lf %lf\n", x1, y1);

  return 0;
}
