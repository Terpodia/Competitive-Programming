#include <iostream>
using namespace std;

int n;
string s;

void solve() {
  int ans = 0;
  for (int i = 0; i < n - 1; i++) {
    int cntPlus = 0, cntMinus = 0, cntExtra = 0, acc = 0;
    for (int j = i; j < n; j++) {
      (s[j] == '-') ? cntMinus++ : cntPlus++;
      if (s[j] == '-')
        acc++;
      else
        cntExtra += acc / 2, acc = 0;

      if (cntPlus > cntMinus) continue;
      if ((cntMinus - cntPlus) % 3 != 0) continue;

      int x = (cntMinus - cntPlus) / 3;
      if (cntExtra + (acc / 2) >= x) ans++;
    }
  }
  cout << ans << "\n";
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int tt;
  cin >> tt;
  while (tt--) {
    cin >> n >> s;
    solve();
  }
  return 0;
}
