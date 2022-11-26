#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

const int MAXN = 1e5;

int n, k, a[MAXN];

bool can() {
  int cnt = 1;
  int b[n];
  for (int i = 0; i < n; i++) b[i] = a[i];
  sort(b, b + n);

  map<int, int> mp;

  for (int i = 0; i < n; i++) mp[b[i]] = i;

  for (int i = 1; i < n; i++)
    if (mp[a[i]] - mp[a[i - 1]] != 1) cnt++;

  return cnt <= k;
}

int main() {
  int t;
  scanf("%d", &t);

  while (t--) {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    (can()) ? puts("YES") : puts("NO");
  }

  return 0;
}
