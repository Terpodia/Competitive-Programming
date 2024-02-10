#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    ll a[n];
    for (int i = 0; i < n; i++) scanf("%lld", a + i);

    ll pref[n + 1];
    pref[0] = 0;
    for (int i = 1; i <= n; i++) pref[i] = pref[i - 1] + a[i - 1];
    ll maxi = 0, mini = 0, k = 0;
    for (int i = 1; i <= n; i++) {
      if (pref[i] - pref[maxi] < mini) {
        mini = pref[i] - pref[maxi];
        k = pref[maxi];
      }
      if (pref[maxi] < pref[i]) maxi = i;
    }

    cout << k << "\n";
  }
  return 0;
}
