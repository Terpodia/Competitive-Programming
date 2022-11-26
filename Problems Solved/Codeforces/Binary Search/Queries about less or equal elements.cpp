#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void fastIO() { cin.tie(0)->sync_with_stdio(0); }

int main() {
  fastIO();
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  vector<pair<int, int>> b(m);

  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < m; i++) {
    cin >> b[i].first;
    b[i].second = i;
  }

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  int ans[m];

  for (int i = 0; i < m; i++) {
    auto it = upper_bound(a.begin(), a.end(), b[i].first);
    if (it == a.begin())
      ans[b[i].second] = 0;
    else
      ans[b[i].second] = it - a.begin();
  }

  for (int i = 0; i < m; i++) printf("%d ", ans[i]);

  puts("");

  return 0;
}
