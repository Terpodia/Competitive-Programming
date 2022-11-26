#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    int a[n];
    vector<bool> b(n, true);
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    bool flag = true;

    sort(a, a + n);
    vector<int> ans;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < (int)ans.size(); j++) {
        if (a[i] == ans[j]) {
          flag = false;
          break;
        }
      }
      b[i] = flag;
      if (flag) ans.push_back(a[i]);
      flag = true;
    }

    for (int i = 0; i < n; i++) {
      if (!b[i]) ans.push_back(a[i]);
    }

    for (int i = 0; i < n; i++) printf("%d ", ans[i]);
    printf("\n");
  }

  return 0;
}
