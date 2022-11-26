#include <iostream>
using namespace std;
using ll = long long;

const int MAXN = 2e5;

int n, q;
ll a[MAXN];

int main() {
  scanf("%d%d", &n, &q);
  for (int i = 0; i < n; i++) scanf("%lld", a + i);

  ll pref[n + 1];
  pref[0] = 0;
  for (int i = 1; i <= n; i++) pref[i] = pref[i - 1] ^ a[i - 1];

  while (q--) {
    int l, r;
    scanf("%d%d", &l, &r);
    printf("%lld\n", pref[r] ^ pref[l - 1]);
  }

  return 0;
}
