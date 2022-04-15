#include <iostream>
#include <vector>
using namespace std;

#define sz(x) (int)x.size()

struct operation {
  int r1, c1, r2, c2;
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    string s[n];
    for (int i = 0; i < n; i++) cin >> s[i];
    if (s[0][0] == '1')
      cout << "-1\n";
    else {
      vector<operation> ans;
      for (int i = n - 1; i > -1; i--) {
        for (int j = m - 1; j > 0; j--) {
          if (s[i][j] == '1') ans.push_back({i, j - 1, i, j});
        }
      }
      for (int i = n - 1; i > 0; i--) {
        if (s[i][0] == '1') ans.push_back({i - 1, 0, i, 0});
      }
      cout << sz(ans) << "\n";
      for (int i = 0; i < sz(ans); i++) {
        cout << ans[i].r1 + 1 << " " << ans[i].c1 + 1 << " " << ans[i].r2 + 1
             << " " << ans[i].c2 + 1 << "\n";
      }
    }
  }
  return 0;
}

