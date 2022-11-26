#include <algorithm>
#include <iostream>
using namespace std;

typedef long long ll;

int main() {
  ll a, b, c;
  scanf("%lld%lld%lld", &a, &b, &c);

  ll ans = c * 2;
  if (a < b) swap(a, b);
  a = min(a, b + 1);
  ans += a + b;

  printf("%lld\n", ans);

  return 0;
}
