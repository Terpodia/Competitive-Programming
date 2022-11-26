#include <iostream>
using namespace std;

const int INF = 1e9;

int n;
string s;

void calc(int dp[][2]) {
  for (int i = n - 1; i >= 0; i--) {
    if (i == 0) {
      if (s[i] == '?')
        dp[i][0] = min(dp[i + 1][0], dp[i + 1][1]);

      else {
        int c = (s[i] == 'R');
        dp[i][0] = dp[i + 1][c];
      }

      continue;
    }

    for (int j = 0; j < 2; j++) {
      if (s[i] == '?')
        dp[i][j] = (j == 0) ? min(dp[i + 1][0] + 1, dp[i + 1][1])
                            : min(dp[i + 1][0], dp[i + 1][1] + 1);

      else {
        int c = (s[i] == 'R');
        dp[i][j] = (c == j) ? dp[i + 1][c] + 1 : dp[i + 1][c];
      }
    }
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;

  while (t--) {
    cin >> n >> s;
    int dp[n + 1][2];
    for (int i = 0; i <= n; i++)
      for (int j = 0; j < 2; j++) dp[i][j] = INF;

    dp[n][0] = dp[n][1] = 0;

    calc(dp);

    int pre;
    if (s[0] != '?')
      pre = (s[0] == 'R');
    else
      pre = (dp[1][0] < dp[1][1]) ? 0 : 1;

    (pre == 0) ? cout << 'B' : cout << 'R';

    for (int i = 1; i < n; i++) {
      if (s[i] != '?')
        pre = (s[i] == 'R');
      else {
        if (pre == 0)
          pre = (dp[i + 1][0] + 1 < dp[i + 1][1]) ? 0 : 1;
        else
          pre = (dp[i + 1][0] < dp[i + 1][1] + 1) ? 0 : 1;
      }

      (pre == 0) ? cout << 'B' : cout << 'R';
    }

    cout << "\n";
  }

  return 0;
}
