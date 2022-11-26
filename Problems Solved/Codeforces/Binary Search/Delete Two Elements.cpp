#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
typedef long double ld;

#define FOR(i, x, n) for (int i = (x); i < (int)(n); i++)
#define ALL(x) x.begin(), x.end()

int aux;

bool check_integer(ld x) { return ((ll)ceill(x) == (ll)floorl(x)); }

int bs(vector<ll>& a, int i, ll s) {
  ll n = (int)a.size();
  int l = i + 1, r = (int)n - 1;

  while (r > l) {
    int mid = l + (r - l + 1) / 2;
    if ((s - a[i] - a[mid]) * n >= s * (n - 2))
      l = mid;
    else
      r = mid - 1;
  }

  return l;
}

int main() {
  int t;
  aux = scanf("%d", &t);
  while (t--) {
    int n;
    aux = scanf("%d", &n);
    vector<ll> a(n);
    FOR(i, 0, n) aux = scanf("%lld", &a[i]);
    sort(ALL(a));

    ll ans = 0, s = 0;
    FOR(i, 0, n) s += a[i];

    FOR(i, 0, n - 1) {
      /*
      ld x = (ld)(s*n-2*s) / (ld)(n);
      if(!check_integer(x)) continue;
      ll aj = s - a[i] - ((s*n - 2*s) / n);

      auto l = lower_bound(a.begin() + i + 1, a.end(), aj);
      if(l == a.end() || *l != aj) continue;
      auto r = upper_bound(a.begin() + i + 1, a.end(), aj);

      ans += (ll)distance(l,r);
      */

      int j = bs(a, i, s);
      if ((ll)n * (s - a[i] - a[j]) == s * (ll)(n - 2)) {
        auto l = lower_bound(a.begin() + i + 1, a.end(), a[j]);
        auto r = upper_bound(a.begin() + i + 1, a.end(), a[j]);
        ans += (ll)distance(l, r);
      }
    }

    printf("%lld\n", ans);
  }

  return 0;
}
