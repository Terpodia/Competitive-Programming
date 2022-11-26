#include <cstdio>
#include <map>
using namespace std;

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  int a[n];
  for (int i = 0; i < n; i++) scanf("%d", a + i);

  map<int, int> mp;
  for (int i = 0; i < n; i++) mp[a[i]]++;

  int m = k, ans = 0;

  for (auto& it : mp)
    while (m < it.second) m += k;

  for (auto& it : mp) ans += m - it.second;

  printf("%d\n", ans);

  return 0;
}
