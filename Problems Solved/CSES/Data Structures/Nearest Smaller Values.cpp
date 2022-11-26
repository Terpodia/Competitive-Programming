#include <iostream>
#include <stack>
#include <vector>
using namespace std;
using pi = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<int> a(n), ans(n, 0);
  for (int i = 0; i < n; i++) cin >> a[i];

  stack<pi> s;
  s.push({a[0], 1});

  for (int i = 1; i < n; i++) {
    while (!s.empty()) {
      if (s.top().first < a[i]) {
        ans[i] = s.top().second;
        break;
      }
      s.pop();
    }
    s.push({a[i], i + 1});
  }

  for (int i = 0; i < n; i++) cout << ans[i] << " ";
  cout << "\n";

  return 0;
}
