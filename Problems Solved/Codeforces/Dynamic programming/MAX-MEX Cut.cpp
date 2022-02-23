#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN = 1e5;

int n, dp[MAXN][2][2];
string s[2];

void fastIO() { cin.tie(0)->sync_with_stdio(0); }

int MEX(int f0, int f1) {
  if (!f0) return 0;
  if (!f1) return 1;
  return 2;
}

int solve(int i, int f0, int f1) {
  if (i == n) return MEX(f0, f1);

  int& ret = dp[i][f0][f1];
  if (ret != -1) return ret;

  ret = 0;

  (s[0][i] == '1') ? f1 = 1 : f0 = 1;
  (s[1][i] == '1') ? f1 = 1 : f0 = 1;

  return ret = max(solve(i+1, f0, f1), MEX(f0, f1) + solve(i+1, 0, 0));
}

int main() {
  int t; cin >> t;

  while (t--) {
    cin >> n;
    cin >> s[0] >> s[1];

    memset(dp, -1, sizeof(dp));
    cout << solve(0, 0, 0) << "\n";
  }

  return 0;
}

