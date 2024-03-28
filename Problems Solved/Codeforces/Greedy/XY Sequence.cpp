#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    ll B, x, y;
    scanf("%d%lld%lld%lld", &n, &B, &x, &y);
    ll cur = 0, ans = 0;
    for (int i = 1; i <= n; i++) {
      if (cur + x <= B)
        cur += x;
      else
        cur -= y;
      ans += cur;
    }
    printf("%lld\n", ans);
  }
  return 0;
}
