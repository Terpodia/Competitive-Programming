#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  int n;
  scanf("%d", &n);
  ll a[n];
  for (int i = 0; i < n; i++) scanf("%lld", a + i);
  sort(a, a + n);
  ll s = 0;
  for (int i = 0; i < n - 1; i++) s += a[i];
  if (a[n - 1] > s)
    printf("%lld\n", 2LL * a[n - 1]);
  else
    printf("%lld\n", s + a[n - 1]);
  return 0;
}
