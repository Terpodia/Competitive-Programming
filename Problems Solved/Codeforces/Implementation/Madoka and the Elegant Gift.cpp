#include <iostream>
using namespace std;

#define rep(i, x, n) \
  for (__typeof(n) i = (x); i != (n); i += 1 - 2 * ((x) > (n)))

const int MAXN = 100;

int n, m, a[MAXN][MAXN];
string s[MAXN];

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int tt;
  cin >> tt;
  while (tt--) {
    cin >> n >> m;
    rep(i, 0, n) cin >> s[i];
    bool can = true;
    rep(i, 0, n - 1) rep(j, 0, m - 1) {
      int cnt = 0;
      rep(r, i, i + 2) rep(c, j, j + 2) if (s[r][c] == '1') cnt++;
      if (cnt == 3) can = false;
    }
    (!can) ? cout << "NO\n" : cout << "YES\n";
  }
  return 0;
}
