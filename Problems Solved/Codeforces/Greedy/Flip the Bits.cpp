#include <iostream>
using namespace std;

void fastIO() { cin.tie(0)->sync_with_stdio(false); }

int main() {
  fastIO();
  int t;
  cin >> t;

  while (t--) {
    int n;
    string a, b;
    cin >> n >> a >> b;

    int cnt0, cnt1;
    cnt0 = cnt1 = 0;
    bool can = true;

    for (int i = 0; i < n; i++) {
      (a[i] == '0') ? cnt0++ : cnt1++;

      if (a[i] == b[i] && i == n - 1) break;

      if (a[i] != b[i]) {
        if (i + 1 < n && a[i + 1] != b[i + 1])
          continue;
        else {
          if (cnt0 != cnt1) {
            can = false;
            break;
          }
        }
      }

      else {
        if (i + 1 < n && a[i + 1] == b[i + 1])
          continue;
        else {
          if (cnt0 != cnt1) {
            can = false;
            break;
          }
        }
      }
    }

    if (can)
      cout << "YES\n";
    else
      cout << "NO\n";
  }

  return 0;
}
