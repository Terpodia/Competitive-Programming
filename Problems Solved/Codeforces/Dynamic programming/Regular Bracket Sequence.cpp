/*
*************************************************************
"Si puedes imaginarlo, puedes programarlo" Alejandro Taboada.
*************************************************************
*/

#include <cstring>
#include <iostream>
using namespace std;

#define sz(x) (int)x.size()
#define forn(i, x, n) for (int i = (x); i < (int)n; i++)

void fastIO() { cin.tie(0)->sync_with_stdio(0); }

string s;
bool can = false;
int dp[200][200];

bool solve(int i, int cnt) {
  if (i == sz(s)) {
    can |= cnt == 0;
    return cnt == 0;
  }

  if (cnt < 0) return false;
  int& ret = dp[i][cnt];

  if (ret != -1) return dp[i][cnt];

  if (s[i] != '?') {
    if (s[i] == '(') return (ret = solve(i + 1, cnt + 1));
    return (ret = solve(i + 1, cnt - 1));
  }

  ret = max(solve(i + 1, cnt + 1), solve(i + 1, cnt - 1));
  can |= ret;
  return ret;
}

int main() {
  fastIO();
  int t;
  cin >> t;

  while (t--) {
    cin >> s;
    can = false;
    memset(dp, -1, sizeof(dp));
    solve(0, 0);

    if (can)
      cout << "YES\n";
    else
      cout << "NO\n";
  }

  return 0;
}
