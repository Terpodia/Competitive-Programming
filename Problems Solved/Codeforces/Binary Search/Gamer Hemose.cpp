#include <algorithm>
#include <iostream>
using namespace std;
int aux;

typedef long long ll;

const ll INF = 1e9 + 7;

bool f(ll m, ll a, ll b, ll H) {
  return ((a * ((m + 1) / 2)) + (b * (m / 2)) >= H);
}

ll bs(ll a, ll b, ll H) {
  ll l = 0, r = INF;

  while (r > l) {
    ll mid = l + (r - l) / 2;
    if (f(mid, a, b, H))
      r = mid;
    else
      l = mid + 1;
  }

  return r;
}

int main() {
  int t;
  aux = scanf("%d", &t);
  while (t--) {
    int n, H;
    aux = scanf("%d%d", &n, &H);
    int a[n];
    for (int i = 0; i < n; i++) aux = scanf("%d", a + i);

    sort(a, a + n, greater<int>());
    printf("%lld\n", bs(a[0], a[1], H));
  }

  return 0;
}
