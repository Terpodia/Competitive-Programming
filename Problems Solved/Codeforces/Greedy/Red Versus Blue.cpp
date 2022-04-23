#include <iostream>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, r, b;
    cin >> n >> r >> b;

    int k = r / (b + 1), m = r % (b + 1);

    while (b > 0 || r > 0) {
      for (int i = 0; i < k; i++) {
        if (r == 0) break;
        cout << "R";
        r--;
      }
      if (b > 0) {
        cout << "B";
        b--;
      }
      if (m > 0) {
        cout << "R";
        r--, m--;
      }
    }
    cout << "\n";
  }
  return 0;
}

