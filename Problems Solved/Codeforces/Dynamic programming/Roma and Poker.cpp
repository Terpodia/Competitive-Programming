#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

const int MAXN = 1e3 + 100;
const int MAXK = MAXN * 2;

void fastIO() { cin.tie(0)->sync_with_stdio(0); }

int n, k;
string s;

int dp[MAXN][MAXN * 2];

bool can = false;

int calc(int i = 0, int cnt = 0) {
  int& ret = (cnt >= 0) ? dp[i][cnt] : dp[i][MAXK + cnt];

  if (i == n) {
    if (abs(cnt) == k) can = true;
    return ret = (abs(cnt) == k) ? 1 : 0;
  }

  if (abs(cnt) == k) return ret = 0;

  if (ret != -1) return ret;

  if (s[i] != '?') {
    int x = 0;
    if (s[i] == 'W')
      x = 1;
    else if (s[i] == 'L')
      x = -1;

    ret = calc(i + 1, cnt + x);
  }

  else {
    int a = calc(i + 1, cnt), b = calc(i + 1, cnt + 1),
        c = calc(i + 1, cnt - 1);

    if (a == 1 || b == 1 || c == 1)
      ret = 1;
    else
      ret = 0;
  }

  return ret;
}

string solve(int i, int cnt) {
  if (i == n) return "";
  string ret;

  if (s[i] != '?') {
    int x = 0;
    if (s[i] == 'W')
      x = 1;
    else if (s[i] == 'L')
      x = -1;

    ret.push_back(s[i]);
    return ret + solve(i + 1, cnt + x);
  }

  int x = (cnt >= 0) ? cnt : MAXN * 2 + cnt;
  int sum = 0;

  if (dp[i + 1][x] == 1)
    ret.push_back('D');
  else if (dp[i + 1][(x + 1) % MAXK] == 1) {
    ret.push_back('W');
    sum = 1;
  } else {
    ret.push_back('L');
    sum = -1;
  }

  return ret + solve(i + 1, cnt + sum);
}

int main() {
  fastIO();
  cin >> n >> k;
  cin >> s;

  memset(dp, -1, sizeof(dp));

  calc();

  if (!can)
    cout << "NO\n";

  else {
    cout << solve(0, 0) << "\n";
  }

  return 0;
}
