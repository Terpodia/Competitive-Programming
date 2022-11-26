#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

void fastIO() { cin.tie(0)->sync_with_stdio(0); }

const int MAX = 1e6 + 7;

int main() {
  fastIO();
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a.begin(), a.end());

  int ans = 0;

  bool check[MAX];
  memset(check, 0, sizeof(check));

  for (int i = 0; i < n; i++) {
    if (!check[a[i]]) {
      check[a[i]] = true;

      for (int j = 1; j <= (MAX * 2) / a[i]; j++) {
        auto it = lower_bound(a.begin(), a.end(), a[i] * j);
        if (it == a.begin()) continue;
        it--;
        if (*it > a[i]) ans = max(ans, *it % a[i]);
      }
    }
  }

  cout << ans << "\n";

  return 0;
}
