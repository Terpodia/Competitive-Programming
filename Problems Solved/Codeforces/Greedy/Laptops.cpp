#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  pair<int, int> l[n];
  for (int i = 0; i < n; i++) scanf("%d%d", &l[i].first, &l[i].second);

  sort(l, l + n);

  int suff[n];
  suff[n - 1] = l[n - 1].second;

  for (int i = n - 2; i >= 0; i--) suff[i] = min(suff[i + 1], l[i].second);

  bool can = false;

  for (int i = 0; i < n - 1; i++) {
    can |= (l[i].second > suff[i + 1]);
  }

  (!can) ? puts("Poor Alex") : puts("Happy Alex");

  return 0;
}
