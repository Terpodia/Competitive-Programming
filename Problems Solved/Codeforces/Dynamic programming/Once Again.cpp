#include <algorithm>
#include <cstdio>
#include <map>
#include <vector>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

const ll INF = 1e18;

int n, T;
vi a;

void compress() {
  vi b = a;
  sort(b.begin(), b.end());
  map<int, int> mp;

  int curr = 0;
  forn(i, n) if (mp.find(b[i]) == mp.end()) mp[b[i]] = curr, curr++;

  forn(i, n) a[i] = mp[a[i]];
}

vi LIS(vi& b) {
  vi dp(n, 0);

  int m = -1;
  for (int i = n - 1; i >= 0; i--)
    if (b[i] != -1) {
      m = i;
      break;
    }

  if (m != -1) dp[m] = 1;

  for (int i = m - 1; i >= 0; i--) {
    if (b[i] == -1) continue;

    dp[i] = 1;
    for (int j = i + 1; j <= m; j++) {
      if (b[j] != -1 && b[j] >= b[i]) dp[i] = max(dp[i], dp[j] + 1);
    }
  }

  return dp;
}

vvi op(vvi& b, vvi& c) {
  int m = (int)b.size();
  vvi ret(m, vi(m, -INF));

  forn(i, m) forn(j, m) forn(z, m) ret[i][j] =
      max(ret[i][j], b[i][z] + c[z][j]);

  return ret;
}

vvi exp(vvi m, int k) {
  vvi ret((int)m.size(), vi((int)m.size()));
  ;

  while (k) {
    if (k & 1) ret = op(ret, m);
    m = op(m, m);
    k >>= 1;
  }

  return ret;
}

int main() {
  scanf("%d%d", &n, &T);
  a = vi(n);
  forn(i, n) scanf("%lld", &a[i]);
  compress();

  vvi v(100);
  vi b(n, -1);
  vvi m(n, vi(n, -INF));

  forn(i, n) v[a[i]].push_back(i);

  forn(i, 100) {
    for (ll j : v[i]) b[j] = i;
    vi lis = LIS(b);
    for (ll j : v[i]) forn(z, n) if (b[z] != -1) m[z][j] = lis[z];
  }

  m = exp(m, T);

  ll ans = 0;

  forn(i, n) forn(j, n) ans = max(ans, m[i][j]);

  printf("%lld\n", ans);

  return 0;
}
