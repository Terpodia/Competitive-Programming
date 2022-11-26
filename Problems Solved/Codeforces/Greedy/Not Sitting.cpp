#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<int> ans;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) {
        int v = max(i + j, n - i + m - j - 2);
        v = max(v, max(i + m - j - 1, n - i - 1 + j));
        ans.push_back(v);
      }
    sort(ans.begin(), ans.end());
    for (int v : ans) printf("%d ", v);
    puts("");
  }
  return 0;
}
