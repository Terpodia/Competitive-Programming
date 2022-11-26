#include <algorithm>
#include <cstdio>
#include <map>
#include <queue>
using namespace std;

#define sz(x) (int)x.size()

int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    map<int, int> mp;
    for (int i = 0; i < n; i++) mp[a[i]]++;
    int v, cnt;
    v = cnt = -1;
    for (auto [b, c] : mp)
      if (c > cnt) v = b, cnt = c;

    int ans = 0;
    while (sz(mp) > 1) {
      ans++;
      cnt = mp[v];
      queue<int> q;
      for (auto& [b, c] : mp) {
        if (cnt == 0) break;
        if (b == v) continue;
        int r = min(cnt, c);
        cnt -= r, c -= r, mp[v] += r, ans += r;
        if (c == 0) q.push(b);
      }
      while (!q.empty()) mp.erase(q.front()), q.pop();
    }
    printf("%d\n", ans);
  }
  return 0;
}
