#include <iostream>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    int t = 0;
    if ((n - 1) % 3 == 0) {
      while (n > 0) {
        cout << t + 1;
        n -= (t == 0) ? 1 : 2;
        t++, t %= 2;
      }
    } else {
      while (n > 0) {
        cout << 1 - t + 1;
        n -= (t == 0) ? 2 : 1;
        t++, t %= 2;
      }
    }
    cout << "\n";
  }
  return 0;
}

