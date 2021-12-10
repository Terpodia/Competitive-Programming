#include <iostream>
using namespace std;

void fastIO() { cin.tie(0)->sync_with_stdio(0); }

int main() {
  fastIO();
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    string ans;
    if (n%2 != 0) ans.push_back('7'), n -= 3;
    while (n > 0) ans.push_back('1'), n -= 2;
    cout << ans << "\n";
  }

  return 0;
}

