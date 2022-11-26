#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

#define sz(x) (int)x.size()

const int MAXSZ = 2e5;

string s;
vector<int> pos[26];

int dp[MAXSZ];

int solve(int i) {
  if (i == sz(s)) return 0;
  int& ret = dp[i];
  if (ret != -1) return ret;
  if (i == sz(s) - 1) return ret = solve(i + 1) + 1;
  ret = solve(i + 1) + 1;
  auto it = upper_bound(pos[s[i] - 'a'].begin(), pos[s[i] - 'a'].end(), i);
  if (it != pos[s[i] - 'a'].end()) ret = min(ret, *it - i - 1 + solve(*it + 1));
  return ret;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int tt;
  cin >> tt;
  while (tt--) {
    cin >> s;
    for (int i = 0; i < sz(s); i++) pos[s[i] - 'a'].push_back(i);
    memset(dp, -1, sizeof(dp));
    cout << solve(0) << "\n";
    for (int i = 0; i < 26; i++) pos[i].clear();
  }
  return 0;
}
