#include <iostream>
using namespace std;
using ull = unsigned long long;

void fastIO() { cin.tie(0)->sync_with_stdio(0); }

int main() {
  fastIO();
  int t;
  cin >> t;

  while (t--) {
    ull n;
    cin >> n;

    int ans = 1;
    ull acc = 0;
    ull cnt = 1;
    bool can = true;

    while (n != acc) {
      if (acc + (ull)2050 * cnt == n)
        acc += 2050 * cnt;
      else if (acc + (ull)2050 * cnt < n)
        cnt *= 10;
      else {
        acc += (ull)2050 * (ull)(cnt / 10);
        cnt = 1;
        ans++;

        if (acc != n && acc + (ull)2050 > n) {
          can = false;
          break;
        }
      }
    }

    if (can)
      cout << ans << "\n";
    else
      cout << "-1\n";
  }

  return 0;
}
