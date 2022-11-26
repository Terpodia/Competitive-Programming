#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    ll a[n], b[n], c[n];
    for (int i = 0; i < n; i++) scanf("%lld", a + i);
    c[0] = 0, b[0] = a[0];
    for (int i = 1; i < n; i++) b[i] = a[i] + b[i - 1], c[i] = b[i - 1];

    bool can = true;
    for (int i = 0; i < n; i++) can &= b[i] >= 0 && c[i] >= 0;
    int j = n - 2;
    for (int i = 0; i < n; i++)
      if (b[i] == 0) {
        j = i;
        break;
      }
    for (int i = j + 1; i < n; i++) can &= b[i] == 0;
    (can) ? puts("YES") : puts("NO");
  }
  return 0;
}
