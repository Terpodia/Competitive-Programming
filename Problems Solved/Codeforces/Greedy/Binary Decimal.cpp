#include <algorithm>
#include <iostream>
using namespace std;

void fastIO() { cin.tie(0)->sync_with_stdio(0); }

int main() {
  fastIO();
  int t;
  cin >> t;

  while (t--) {
    string n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < (int)n.size(); i++) ans = max(ans, n[i] - '0');
    cout << ans << "\n";
  }

  return 0;
}
