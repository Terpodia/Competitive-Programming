#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define rep(i, x, n) for (int i = (x); i != (n); i += 1 - 2 * ((x) > (n)))

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;

const int MAXC = 1e5 + 1;

int n, m;
vvll c;
vll colors[MAXC][2];

int main() {
  scanf("%d%d", &n, &m);
  c = vvll(n, vll(m));
  rep(i, 0, n) rep(j, 0, m) scanf("%lld", &c[i][j]);

  rep(i, 0, n) rep(j, 0, m) {
    colors[c[i][j]][0].push_back(i);
    colors[c[i][j]][1].push_back(j);
  }

  ll ans = 0;

  rep(i, 0, MAXC) {
    if (colors[i][0].empty()) continue;
    sort(all(colors[i][0]));
    sort(all(colors[i][1]));

    ll suff[sz(colors[i][0]) + 1][2];
    suff[sz(colors[i][0])][0] = suff[sz(colors[i][1])][1] = 0;

    rep(k, 0, 2) rep(j, sz(colors[i][k]) - 1, -1) {
      suff[j][k] = suff[j + 1][k] + colors[i][k][j];
    }

    rep(k, 0, 2) rep(j, 0, sz(colors[i][k]) - 1) {
      ans += suff[j + 1][k] - colors[i][k][j] * (sz(colors[i][k]) - j - 1);
    }
  }

  printf("%lld\n", ans);

  return 0;
}
