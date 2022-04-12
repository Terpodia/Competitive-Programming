#include <iostream>
#include <vector>
using namespace std;

#define sz(x) (int)x.size()

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    string s;
    cin >> n >> s;
    vector<int> p;
    for (int i = 0; i < n; i++)
      if (s[i] == '0') p.push_back(i);
    int ans = 0;
    for (int i = 0; i < sz(p) - 1; i++) {
      if (p[i + 1] - p[i] < 3) ans += 3 - p[i + 1] + p[i];
    }
    cout << ans << "\n";
  }
  return 0;
}

