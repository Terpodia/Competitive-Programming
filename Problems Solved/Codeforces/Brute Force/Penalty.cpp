#include <algorithm>
#include <iostream>
using namespace std;

string s;

void fastIO() { cin.tie(0)->sync_with_stdio(0); }

int solve(int i, int msk) {
  if (i == 10) {
    int t = 0, p1 = 0, p2 = 0, cnt1 = 5, cnt2 = 5;

    for (; t < 10; t++) {
      if (p1 < p2 && p1 + cnt1 < p2)
        break;
      else if (p2 < p1 && p2 + cnt2 < p1)
        break;

      if ((msk & (1 << t)) != 0) (t % 2 == 0) ? p1++ : p2++;

      (t % 2 == 0) ? cnt1-- : cnt2--;
    }

    return t;
  }

  if (s[i] == '1') return solve(i + 1, msk | (1 << i));

  if (s[i] == '0') return solve(i + 1, msk);

  return min(solve(i + 1, msk | (1 << i)), solve(i + 1, msk));
}

int main() {
  fastIO();
  int t;
  cin >> t;

  while (t--) {
    cin >> s;
    cout << solve(0, 0) << "\n";
  }

  return 0;
}
