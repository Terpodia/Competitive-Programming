#include <algorithm>
#include <iostream>
using namespace std;

#define sz(x) (int)x.size()

const int INF = 1e9;

void fastIO() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}

int solve(string s1, string s2) {
  int dp[sz(s1) + 1][sz(s2) + 1];
  for (int i = 0; i <= sz(s1); i++)
    for (int j = 0; j <= sz(s2); j++) dp[i][j] = INF;

  for (int i = 0; i <= sz(s1); i++) dp[i][0] = i;
  for (int j = 0; j <= sz(s2); j++) dp[0][j] = j;

  for (int i = 1; i <= sz(s1); i++)
    for (int j = 1; j <= sz(s2); j++) {
      if (s1[i - 1] == s2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
      dp[i][j] = min(dp[i][j], min(dp[i - 1][j - 1] + 1,
                                   min(dp[i - 1][j] + 1, dp[i][j - 1] + 1)));
    }

  return dp[sz(s1)][sz(s2)];
}

int main(void) {
  fastIO();
  string s1, s2;
  cin >> s1 >> s2;

  cout << solve(s1, s2) << "\n";

  return 0;
}
