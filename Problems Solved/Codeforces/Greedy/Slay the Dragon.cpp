#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;

int aux;

int main() {
  int n;
  aux = scanf("%d", &n);
  vector<ll> a(n);
  for (int i = 0; i < n; i++)
    aux = scanf("%lld", &a[i]);

  int m;
  aux = scanf("%d", &m);

  ll x[m], y[m];
  for (int i = 0; i < m; i++)
    aux = scanf("%lld%lld", x + i, y + i);

  sort(a.begin(), a.end());
  ll s = 0;
  for (int i = 0; i < n; i++)
    s += a[i];

  for (int i = 0; i < m; i++) {
    auto it = lower_bound(a.begin(), a.end(), x[i]);
    if (it == a.end())
      it--;

    if (it == a.begin()) {
      printf("%lld\n", max((ll)0, y[i] - s + *it) + max((ll)0, x[i] - *it));
    } else {
      ll a1 = max((ll)0, y[i] - s + *it) + max((ll)0, x[i] - *it);
      it--;
      ll a2 = max((ll)0, y[i] - s + *it) + max((ll)0, x[i] - *it);

      printf("%lld\n", min(a1, a2));
    }
  }

  return 0;
}
