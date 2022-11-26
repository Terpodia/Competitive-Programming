#include <algorithm>
#include <iostream>
#include <tuple>
using namespace std;

// ax + by = gdc(a, b)
// bx + (a % b)y = gcd(a, b)
// bx + (a - (a / b) * b)y = gcd(a, b)
// ay + bx + (- (a / b) * by) = gcd(a, b)
// ay + b (x - (a / b) * y)

// (a * x) % m = 1 % m
// a * x = (1 + m*y)
// a*x - m*y = 1

tuple<int, int, int> euclidExtend(int a, int b) {
  if (b == 0) return {1, 0, a};
  auto [x, y, g] = euclidExtend(b, a % b);
  return {y, x - (a / b) * y, g};
}

int main() {
  int a, m;
  cin >> a >> m;
  auto [x, y, g] = euclidExtend(a, m);

  x %= m, x += m, x %= m;

  if (g != 1)
    cout << a << " has no inverse mod " << m << "\n";
  else
    cout << a << "^-1 mod " << m << " = " << x << "\n";

  return 0;
}
