#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

const ld PI = 3.14159265359;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cout << fixed << setprecision(9);

  int n, R, r;
  cin >> n >> R >> r;
  ld theta = (ld)360 / (ld)(n * 2);
  ld h = R * sin(theta * PI / (ld)180);
  ld A = ((r * h) / (ld)2) * (ld)(2 * n);
  cout << A << "\n";
  return 0;
}
