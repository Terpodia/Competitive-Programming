#include <algorithm>
#include <iostream>
using namespace std;

#define sz(x) (int)x.size()

void fastIO() { cin.tie(0)->sync_with_stdio(0); }

int main() {
  fastIO();
  int t;
  cin >> t;

  while (t--) {
    string n;
    cin >> n;
    int ans = 10;

    for (int i = 0; i < sz(n); i++) {
      if ((int)(n[i] - '0') % 2 == 0) {
        if (i == sz(n) - 1)
          ans = 0;
        else if (i == 0)
          ans = min(ans, 1);
        else
          ans = min(ans, 2);
      }
    }

    if (ans == 10)
      cout << "-1\n";
    else
      cout << ans << "\n";
  }

  return 0;
}
