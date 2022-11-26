#include <cmath>
#include <cstdio>
using namespace std;
using ll = long long;
using ld = long double;

ld X, Y, R;

ll calc(ll y2) {
  ld root = sqrt(R * R - (y2 - Y) * (y2 - Y));
  ll left = ceil(X - root), right = floor(X + root);

  return right - left + (ll)1;
}

int main() {
  scanf("%Lf%Lf%Lf", &X, &Y, &R);

  ll ans = 0;

  R = nextafter(R, INFINITY);

  ll from = ceil(Y - R), to = floor(Y + R);

  for (ll i = from; i <= to; i++) ans += calc(i);

  printf("%lld\n", ans);

  return 0;
}
