#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;

int main() {
  int t;
  scanf("%d", &t);

  while (t--) {
    long long r, b, d;
    scanf("%lld%lld%lld", &r, &b, &d);
    if (r > b) swap(r, b);

    if (b <= r * (d + 1))
      puts("YES");
    else
      puts("NO");
  }

  return 0;
}
