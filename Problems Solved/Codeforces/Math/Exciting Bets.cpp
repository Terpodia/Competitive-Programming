#include <algorithm>
#include <iostream>
using namespace std;
using ll = long long;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    ll a, b;
    scanf("%lld%lld", &a, &b);
    if (a < b) swap(a, b);

    if (a == b)
      puts("0 0");
    else
      printf("%lld %lld\n", a - b, min(b % (a - b), a - b - b % (a - b)));
  }

  return 0;
}
