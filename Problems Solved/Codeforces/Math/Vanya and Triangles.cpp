#include <cstdio>
#include <cstring>
#include <map>
using namespace std;

typedef long long ll;

const int MAXN = 2007;

ll dp[MAXN][MAXN];
int n;
pair<ll, ll> p[MAXN];

ll gcd(ll a, ll b) { return (b == 0) ? a : gcd(b, (a % b + b) % b); }

ll comb(int m, int k) {
  if (m == k || k == 0) return 1;
  if (m < k) return 0;

  ll& ret = dp[m][k];
  if (ret != -1) return ret;

  return ret = comb(m - 1, k - 1) + comb(m - 1, k);
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%lld%lld", &p[i].first, &p[i].second);

  memset(dp, -1, sizeof(dp));

  ll ans = comb(n, 3);
  ll cnt = 0;

  map<pair<ll, ll>, ll> mp;

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      ll y = p[i].second - p[j].second;
      ll x = p[i].first - p[j].first;
      ll g = gcd(y, x);

      y /= g;
      x /= g;

      cnt += mp[make_pair(y, x)];
      mp[make_pair(y, x)]++;
    }

    mp.clear();
  }

  ans -= cnt;

  printf("%lld\n", ans);

  return 0;
}
