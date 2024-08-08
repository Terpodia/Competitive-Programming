#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

const int MAXN = 1e6 + 10;

int main() {
  int n;
  scanf("%d", &n);
  int x[n];
  for (int i = 0; i < n; i++) scanf("%d", x + i);
  vector<ll> cnt(MAXN, 0), d(MAXN, 0);
  for (int i = 0; i < n; i++) cnt[x[i]]++;
  for (int i = MAXN - 1; i > 0; i--) {
    ll D = 0, s = 0;
    for (int j = i; j < MAXN; j += i) {
      D += cnt[j];
      s += d[j];
    }
    D = (D * (D - 1LL)) / 2LL;
    d[i] = D - s;
    if (d[i] > 0) {
      printf("%d\n", i);
      return 0;
    }
  }
  return 0;
}
