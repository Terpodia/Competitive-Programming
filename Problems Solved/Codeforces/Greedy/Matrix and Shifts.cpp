#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    string s[n];
    for (int i = 0; i < n; i++) cin >> s[i];
    vector<int> cnt(n, 0);

    int numOfOnes = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (s[i][j] == '1') {
          numOfOnes++;
          cnt[(i - j + n) % n]++;
        }
      }
    }
    int ans = INF;
    for (int i = 0; i < n; i++) ans = min(ans, numOfOnes - cnt[i] + n - cnt[i]);
    cout << ans << "\n";
  }
  return 0;
}

