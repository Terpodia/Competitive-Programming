#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
int aux;

#define sz(x) (int)x.size()

int main() {
  int TC;
  aux = scanf("%d", &TC);
  while (TC--) {
    int n;
    aux = scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) aux = scanf("%d", a + i);

    bool ok[n + 1];
    memset(ok, false, sizeof(ok));

    vector<int> cnt;

    for (int i = 0; i < n; i++) {
      if (a[i] >= 1 && a[i] <= n && !ok[a[i]])
        ok[a[i]] = true;
      else
        cnt.push_back(((a[i] + 1) / 2) - 1);
    }

    sort(cnt.begin(), cnt.end(), greater<int>());

    int ans = 0;
    bool can = true;
    int pos = 0;

    for (int i = n; i > 0; i--) {
      if (!ok[i]) {
        if (cnt[pos] >= i)
          pos++, ans++, ok[i] = true;
        else {
          can = false;
          break;
        }
      }
    }

    printf("%d\n", (can) ? ans : -1);
  }

  return 0;
}
