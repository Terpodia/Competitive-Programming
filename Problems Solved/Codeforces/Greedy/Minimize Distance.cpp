#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int aux;

typedef long long ll;

#define sz(x) (int)x.size()

const int MAXN = 2e5;

int n, k;
ll x[MAXN];

ll calc(vector<ll>& a) {
  ll ret = a[sz(a) - 1];
  int cnt = 0;

  for (int i = sz(a) - 1 - k; i > -1; i--) {
    if (cnt % k == 0) ret += a[i] * 2;
    cnt++;
  }

  return ret;
}

void solve() {
  vector<ll> a, b;
  for (int i = 0; i < n; i++) {
    if (x[i] >= 0)
      a.push_back(x[i]);
    else
      b.push_back(abs(x[i]));
  }

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  if (!a.empty() && !b.empty())
    printf("%lld\n", calc(a) + calc(b) + min(a[sz(a) - 1], b[sz(b) - 1]));

  else if (a.empty())
    printf("%lld\n", calc(b));

  else
    printf("%lld\n", calc(a));
}

int main() {
  int TC;
  aux = scanf("%d", &TC);
  while (TC--) {
    aux = scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) aux = scanf("%lld", x + i);

    solve();
  }

  return 0;
}
