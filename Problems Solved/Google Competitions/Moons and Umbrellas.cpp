#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
using vi = vector<int>;

const int MAXN = 100;
char a[MAXN];
int X, Y;
vector<vi> dp;

int solve(int i, int lastCharacter) {
  if (i >= (int)strlen(a)) return 0;

  if (dp[i][lastCharacter] != 1e9) return dp[i][lastCharacter];

  int c;
  c = (a[i] == 'C') ? 0 : 1;
  if (a[i] == '?') c = -1;

  if (c == lastCharacter) return dp[i][c] = solve(i + 1, c);
  if (c != -1) {
    if (lastCharacter == 0 && c == 1)
      return dp[i][lastCharacter] = X + solve(i + 1, c);
    return dp[i][lastCharacter] = Y + solve(i + 1, c);
  }

  if (lastCharacter == 0)
    return dp[i][lastCharacter] = min(solve(i + 1, 0), solve(i + 1, 1) + X);
  return dp[i][lastCharacter] = min(solve(i + 1, 1), solve(i + 1, 0) + Y);
}

int main() {
  int t, x = 1;
  scanf("%d", &t);

  while (t--) {
    scanf("%d%d%s", &X, &Y, a);
    dp.clear();
    dp.resize(strlen(a) + 1, vi(2, 1e9));
    int lastCharacter = -1;
    if (a[0] != '?') lastCharacter = (a[0] == 'C') ? 0 : 1;

    int ans = 0;
    if (lastCharacter != -1)
      ans = solve(1, lastCharacter);
    else
      ans = min(solve(1, 0), solve(1, 1));

    printf("Case #%d: %d\n", x, ans);
    x++;
  }

  return 0;
}
