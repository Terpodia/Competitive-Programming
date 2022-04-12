#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define all(x) x.begin(), x.end()

int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    vector<int> cnt(n, 0), p(n, -1);
    for (int i = 1; i < n; i++) {
      scanf("%d", &p[i]);
      cnt[--p[i]]++;
    }
    int ans = 1;
    sort(all(cnt));
    priority_queue<int> pq;
    int d = 1;
    for (int i = 0; i < n; i++) {
      if (cnt[i] == 0) continue;
      ans++, cnt[i] -= 1 + d, d++;
      if (cnt[i] > 0) pq.push(cnt[i]);
    }
    d = 0;
    while (!pq.empty()) {
      int a = pq.top();
      pq.pop();
      if (a - d <= 0) continue;
      a--, d++, ans++;
      pq.push(a);
    }
    printf("%d\n", ans);
  }
  return 0;
}

