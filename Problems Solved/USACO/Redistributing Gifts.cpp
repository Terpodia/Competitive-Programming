// "Si puedes imaginarlo, puedes programarlo" Alejandro Taboada

#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define f first
#define s second
#define rep(i, x, n) \
  for (__typeof(n) i = (x); i != (n); i += 1 - 2 * ((x) > (n)))
#define dbg(x) cout << #x << "=" << x << " ";
#define line cout << "\n=========================================\n";

const int INF = 1e9;

int n, p[500][500];
bool g[500][500];

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n;
  rep(i, 0, n) rep(j, 0, n) {
    cin >> p[i][j];
    p[i][j]--;
    g[i][j] = false;
  }
  int a[n];
  rep(i, 0, n) {
    int k = 0;
    rep(j, 0, n) if (p[i][j] == i) k = j;
    rep(j, k, -1) g[i][p[i][j]] = true;
    a[i] = k;
  }
  rep(k, 0, n) rep(i, 0, n) rep(j, 0, n) g[i][j] |= g[i][k] & g[k][j];

  int ans[n];
  rep(i, 0, n) ans[i] = i;
  rep(i, 0, n) rep(j, 0, a[i]) {
    if (g[p[i][j]][i]) {
      ans[i] = p[i][j];
      break;
    }
  }
  rep(i, 0, n) cout << ans[i] + 1 << "\n";
  return 0;
}

