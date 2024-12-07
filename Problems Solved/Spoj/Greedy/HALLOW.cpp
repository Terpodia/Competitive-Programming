#include <bits/stdc++.h>
using namespace std;

int main() {
  int c, n;
  while (scanf("%d%d", &c, &n) != EOF) {
    if (n == 0 && c == 0) break;
    int a[n];
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    deque<int> ans;
    int sum = 0;
    set<int> used;
    for (int i = 0; i < n; i++) {
      ans.push_back(i + 1);
      sum += a[i];
      sum %= c;
      if (sum == 0) break;
      if (used.find(sum) != used.end()) {
        while (sum != 0) {
          sum -= a[ans[0] - 1];
          sum += c, sum %= c;
          ans.pop_front();
        }
        break;
      }
      used.insert(sum);
    }
    for (int i : ans) printf("%d ", i);
    puts("");
  }
  return 0;
}
