#include <iostream>
#include <vector>
using namespace std;

int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    int a[n], pos[n + 1];
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    for (int i = 0; i < n; i++) pos[a[i]] = i;
    int ans[n];
    vector<pair<int, int>> shifts;
    for (int i = n - 1; i > -1; i--) {
      int currentPos = pos[i + 1];
      for (auto [s, mod] : shifts) currentPos = (currentPos - s + mod) % mod;

      if (currentPos == i)
        ans[i] = 0;
      else {
        shifts.push_back({(currentPos - i + i + 1), i + 1});
        ans[i] = (currentPos - i + i + 1) % (i + 1);
      }
    }
    for (int i = 0; i < n; i++) printf("%d%c", ans[i], " \n"[i == n - 1]);
  }
  return 0;
}

