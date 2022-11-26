#include <algorithm>
#include <cstdio>
using namespace std;

typedef long long ll;

int main() {
  int n;
  scanf("%d", &n);
  ll c[n];
  for (int i = 0; i < n; i++) scanf("%lld", c + i);

  if (n % 2 != 0) n--;
  ll ans = 0;

  for (int i = 0; i < n; i += 2) {
    ll l = c[i] - c[i + 1], r = 0;
    int j = i + 2;

    ans += min(c[i], c[i + 1]);

    while (j < n && l >= 0) {
      ll aux = c[j];
      if (r >= 0)
        l -= r;
      else
        c[j] += abs(r);

      r = c[j + 1] - c[j];
      if (l >= 0 && r >= 0) ans += min(l, r) + 1;

      c[j] = aux;
      j += 2;
    }
  }

  printf("%lld\n", ans);

  return 0;
}
